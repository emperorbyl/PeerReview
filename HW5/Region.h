//
// Created by Stephen Clyde on 3/4/17.
//

#ifndef GEO_REGIONS_REGION_H
#define GEO_REGIONS_REGION_H

#include <string>

class Region {
public:
    typedef enum RegionType { UnknownRegionType, WorldType, NationType, StateType, CountyType, CityType } x;

protected:
    unsigned int    m_id = 0;
    RegionType      m_regionType = UnknownRegionType;
    std::string     m_name;
    unsigned int    m_population = 0;
    double          m_area = 0;
    bool            m_isValid = false;

    // DONE: Add data members to manage sub-regions
    Region**        m_subRegions = nullptr;
    int             m_subCount = 0;
    unsigned int    m_allocated = 0;

private:
    static unsigned int m_nextId;

public:
    static Region* create(std::istream &in);
    static Region* create(const std::string& data);
    static Region* create(RegionType regionType, const std::string& data);
    static std::string regionLabel(RegionType regionType);

protected:
    Region();
    Region(RegionType type, const std::string data[]);
    Region** growArray(Region** array, unsigned int &allocated, int regions);

public:
    ~Region();
    unsigned int getId() const { return m_id; }
    RegionType  getType() const { return m_regionType; }
    std::string getRegionLabel() const;
    const std::string& getName() const { return m_name; }
    void setName(const std::string& name) { m_name = name; }
    unsigned int getPopulation() const { return m_population; }
    void setPopulation(unsigned int population) { m_population = population; }
    double getArea() const { return m_area; }
    void setArea(double area) { m_area = area; }
    bool getIsValid() const { return m_isValid; }
    bool deleteByIndex(int index);


    // DONE: Add methods to manage sub-regions
    void addChild(Region* newChild);
    int getSubRegionCount() const { return m_subCount; }
    Region* getSubRegionByIndex(int nationIndex) const;

    // DONE: Add method to compute total population, as m_population + the total population for all sub-regions
    unsigned int computeTotalPopulation();

    void list(std::ostream& out);
    void display(std::ostream& out, unsigned int displayLevel, bool showChild);
    void save(std::ostream& out);

protected:
    virtual void validate();
    void loadChildren(std::istream& in);
    static unsigned int getNextId();

    // DONE: add whatever other helper methods you might need
    //methods and data members used for ID handling of all Regions created
    static Region** m_allRegions;
    static unsigned int m_totalAllocated;
    static unsigned int m_totalCount;
    void addByID(Region* region);
public:
    static Region* getRegionByID(int id);
    static bool deleteByID(int id);


    //Added some methods elsewhere in this file
};


#endif //GEO_REGIONS_REGION_H
