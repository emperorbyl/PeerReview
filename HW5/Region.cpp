//
// Created by Stephen Clyde on 3/4/17.
//

#include "Region.h"
#include "Utils.h"
#include "World.h"
#include "Nation.h"
#include "State.h"
#include "County.h"
#include "City.h"

#include <iomanip>
#include <iostream>

const std::string regionDelimiter = "^^^";
const int TAB_SIZE = 4;
unsigned int Region::m_nextId = 0;
unsigned int Region::m_totalAllocated = 0;
unsigned int Region::m_totalCount = 0;
Region** Region::m_allRegions = nullptr;

Region* Region::create(std::istream &in)
{
    Region* region = nullptr;
    std::string line;
    std::getline(in, line);
    if (line!="")
    {
        region = create(line);
        if (region!= nullptr)
            region->loadChildren(in);
    }
    return region;
}
Region* Region::create(const std::string& data)
{
    Region* region = nullptr;
    std::string regionData;
    unsigned long commaPos = (int) data.find(",");
    if (commaPos != std::string::npos)
    {
        std::string regionTypeStr = data.substr(0,commaPos);
        regionData = data.substr(commaPos+1);

        bool isValid;
        RegionType regionType = (RegionType) convertStringToInt(regionTypeStr, &isValid);

        if (isValid)
        {
            region = create(regionType, regionData);
        }

    }

    return region;
}

Region* Region::create(RegionType regionType, const std::string& data)
{
    Region* region = nullptr;
    std::string fields[3];
    if (split(data, ',', fields, 3)) {

        // Create the region based on type
        switch (regionType) {
            case WorldType:
                region = new World();
                break;
            case NationType:
                region = new Nation(fields);
                break;
       // DONE: Add cases for State, County, and City
            case StateType:
                region = new State(fields);
                break;
            case CountyType:
                region = new County(fields);
                break;
            case CityType:
                region = new City(fields);
                break;
            default:
                break;
        }

        // If the region isn't valid, get rid of it
        if (region != nullptr && !region->getIsValid()) {
            delete region;
            region = nullptr;
        }
    }

    return region;
}

std::string Region::regionLabel(RegionType regionType)
{
    std::string label = "Unknown";
    switch (regionType)
    {
        case Region::WorldType:
            label = "World";
            break;
        case Region::NationType:
            label = "Nation";
            break;
        case Region::StateType:
            label = "State";
            break;
        case Region::CountyType:
            label = "County";
            break;
        case Region::CityType:
            label = "City";
            break;
        default:
            break;
    }
    return label;
}

Region::Region() { }

Region::Region(RegionType type, const std::string data[]) :
        m_id(getNextId()), m_regionType(type), m_isValid(true)
{

    m_name = data[0];
    m_population = convertStringToUnsignedInt(data[1], &m_isValid);
    if (m_isValid)
        m_area = convertStringToDouble(data[2], &m_isValid);
    if (m_isValid)
        addByID(this);
}

Region::~Region()
{
    // DONE: cleanup any dynamically allocated objects
    delete[] m_subRegions;
    m_allRegions[m_id] = nullptr;
    m_subRegions = nullptr;
    m_allocated = 0;
    m_subCount = 0;
    m_totalCount--;
    m_allRegions[m_id] = nullptr;
}

std::string Region::getRegionLabel() const
{
    return regionLabel(getType());
}

unsigned int Region::computeTotalPopulation()
{
    // DONE: implement computeTotalPopulation, such that the result is m_population + the total population for all sub-regions
    if(m_subCount == 0) return m_population;
    else {
        int subPopulations = 0;
        for(int i = 0; i < m_subCount; i++){
            subPopulations += m_subRegions[i]->computeTotalPopulation();
        }
        return m_population + subPopulations;
    }
}

void Region::list(std::ostream& out)
{
    out << std::endl;
    out << getName() << " : " << m_id << std::endl;
    //DONE: implement the loop in the list method
    // foreach subregion, print out
    //      id    name
    for (int i = 0; i < m_subCount; i++){
        m_subRegions[i]->list(out);
    }
}

void Region::display(std::ostream& out, unsigned int displayLevel, bool showChild)
{
    if (displayLevel>0)
    {
        out << std::setw(displayLevel * TAB_SIZE) << " ";
    }

    unsigned totalPopulation = computeTotalPopulation();
    double area = getArea();
    double density = (double) totalPopulation / area;

    // DONE: compute the totalPopulation using a method

    out << std::setw(6) << getId() << "  "
        << getName() << ", population="
        << totalPopulation
        << ", area=" << area
        << ", density=" << density << std::endl;

    if (showChild)
    {
        // DONE: implement loop in display method
        // foreach subregion
        //      display that subregion at displayLevel+1 with the same showChild value
        for(int i = 0; i < m_subCount; i++){
            m_subRegions[i]->display(out, displayLevel+1, showChild);
        }
    }
}

void Region::save(std::ostream& out)
{
    out << getType()
        << "," << getName()
        << "," << getPopulation()
        << "," << getArea()
        << std::endl;

    // DONE: implement loop in save method to save each sub-region
    // foreach subregion,
    //      save that region
    for(int i = 0; i < m_subCount; i++){
        m_subRegions[i]->save(out);
    }

    out << regionDelimiter << std::endl;
}

/**
 * function that ensures all data in the created Region is valid
 */
void Region::validate()
{
    m_isValid = (m_area!=UnknownRegionType && m_name!="" && m_area>=0);
}

/**
 * recursive function that reads in lines from the "in" stream and adds them as subRegions
 * until the ^^^ delimiter line is reached in the stream
 * @param in the input stream
 */
void Region::loadChildren(std::istream& in)
{
    std::string line;
    bool done = false;
    while (!in.eof() && !done)
    {
        std::getline(in, line);
        line = trim(line);
        if (line==regionDelimiter)
        {
            done = true;
        }
        else
        {
            Region* child = create(line);
            if (child!= nullptr)
            {
                // DONE: Add the new sub-region to this region
                addChild(child);
                child->loadChildren(in);
            }
        }
    }
}

/**
 * @return the next Region ID that hasn't been used
 */

unsigned int Region::getNextId()
{
    if (m_nextId==UINT32_MAX)
        m_nextId=1;

    return m_nextId++;
}

/**
 * grows the subRegion array to be twice the size using a temporary  array
 */
Region** Region::growArray(Region** array, unsigned int &allocated, int regions){
    allocated = allocated * 2;
    Region** newArray = new Region*[allocated];
    for (int i = 0; i < regions; i++) newArray[i] = array[i];
    delete [] array;
    return newArray;
}

/**
 * Adds newChild to the dynamic SubRegion array
 * First checks to see if m_subRegions has been initialized (if m_allocated == 0),
 * and initializes if necessary, and then calls growSubs if necessary, and
 * then finally adds the newChild to the array and increments subCount
 *
 * @param newChild the new Region pointer to be added
 */
void Region::addChild(Region* newChild){
    if(m_allocated == 0)
    {
        m_allocated++;
        m_subRegions = new Region*[1];
    }
    else if (m_subCount == m_allocated) m_subRegions = growArray(m_subRegions, m_allocated, m_subCount);

    m_subRegions[m_subCount++] = newChild;
}

bool Region::deleteByIndex(int index){
    int maxIndex = m_subCount - 1;
    if(index > maxIndex) return false;
    else {
        delete m_subRegions[index];
        int emptyIndex = index;
        while(emptyIndex < maxIndex){
            m_subRegions[emptyIndex] = m_subRegions[emptyIndex+1];
            emptyIndex++;
        }
        m_subRegions[maxIndex] = nullptr;
        m_subCount--;
        return true;
    }
}

Region* Region::getSubRegionByIndex(int nationIndex) const {
    Region* region = nullptr;
    if(nationIndex < m_subCount) region = m_subRegions[nationIndex];
    return region;
}

Region* Region::getRegionByID(int id){
    Region* region = nullptr;
    if (id < m_totalAllocated) region = m_allRegions[id];
    return region;
}

void Region::addByID(Region* region){
    if(m_totalCount == 0) {
        m_totalAllocated++;
        m_allRegions = new Region*[1];
    }
    else if(m_totalAllocated == m_totalCount) m_allRegions = growArray(m_allRegions, m_totalAllocated, m_totalCount);

    m_allRegions[m_totalCount] = region;
    m_totalCount++;
}

bool Region::deleteByID(int id){
    bool deleted = false;
    if(id < m_totalCount && m_allRegions[id]!=nullptr) {
        deleted = true;
        delete m_allRegions[id];
        m_allRegions[id] = nullptr;
    }
    return deleted;
}