//
// Created by Stephen Clyde on 2/3/17.
//

#include "EdgeTester.h"

#include <iostream>
#include <cmath>
#include "../Point.h"
#include "../Edge.h"

void EdgeTester::testEdge01()
{
    std::cout << "Execute EdgeTester::testEdge01" << std::endl;

    Point p0(0,0,0);
    Point p1(1,0,0);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (e.getLength()!=1)
    {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 1)"
                  << std::endl;
        return;
    }

    if (e.getSlopeX()!=INFINITY)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting INFINITY)"
                  << std::endl;
        return;
    }

    if (e.getSlopeY()!=0)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0)"
                  << std::endl;
        return;
    }

    if (e.getSlopeZ()!=0)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 0)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testEdge02()
{
    std::cout << "Execute EdgeTester::testEdge02" << std::endl;

    Point p0(1,0,0);
    Point p1(3,4,5);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (fabs(e.getLength() - 6.708203932) > 0.001)
    {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 6.708203932)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeX() - 0.312347524) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting 0.312347524)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeY() - 0.742781353) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0.742781353)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeZ() - 1.118033989) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 1.118033989)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testParallelEdges()
{
    std::cout << "Execute EdgeTester::testParallelEdges" << std::endl;

    // TODO: Writing a representative set of test cases for edges that are parallel with other

    //slopes are normal integer values
    Point p0(0,0,0);
    Point p1(1,1,1);
    Edge e1(&p0,&p1);

    Point p2(0,0,1);
    Point p3(1,1,2);
    Edge e2(&p2,&p3);

    if(!e1.isParallelTo(e2)){
        std::cout << "Failure in \"e1.isParallelTo(e2)\". Result="
                  << e1.isParallelTo(e2) << " Expected:"
                  << "1\n";
    }

    //one or more slopes involve INFINITY
    Point p4(0,0,0);
    Point p5(0,0,1);
    Edge e3(&p4,&p5);

    Point p6(1,0,0);
    Point p7(1,0,1);
    Edge e4(&p6,&p7);

    if(!e3.isParallelTo(e4)){
        std::cout << "Failure in \"e3.isParallelTo(e4)\". Result="
                  << e3.isParallelTo(e4) << " Expected:"
                  << "1\n";
    }
}

void EdgeTester::testNonParallelEdges()
{
    std::cout << "Execute EdgeTester::testNonParallelEdges" << std::endl;

    // TODO: Writing a representative set of test cases for edges that are not parallel with other

    //edges are blatantly non-parallel
    Point p0(0,0,0);
    Point p1(1,1,1);
    Edge e1(&p0,&p1);

    Point p2(0,0,1);
    Point p3(3,7,1000);
    Edge e2(&p2,&p3);

    if(e1.isParallelTo(e2)){
        std::cout << "Failure in \"e1.isParallelTo(e2)\". Result="
                  << e1.isParallelTo(e2) << " Expected:"
                  << "0\n";
    }

    //edges are only slightly different, should still not be parallel
    Point p4(0,0,0);
    Point p5(0,0,1);
    Edge e3(&p4,&p5);

    Point p6(0,0,0);
    Point p7(0,0.1,1.1);
    Edge e4(&p6,&p7);

    if(e3.isParallelTo(e4)){
        std::cout << "Failure in \"e3.isParallelTo(e4)\". Result="
                  << e3.isParallelTo(e4) << " Expected:"
                  << "0\n";
    }
}

void EdgeTester::testNonLengthEdges()
{
    std::cout << "Execute EdgeTester::testNonLengthEdges" << std::endl;

    // TODO: Writing a representative set of test cases for edges have a length of zero or approximately zero

    Point p0(0,0,0);
    Point p1(0,0,0);
    Edge e1(&p0, &p1);

    if(e1.getLength()>.01){
        std::cout << "Failure in e1.getLength(): should be <.01, is: "
                  << e1.getLength() << std::endl;
    }

    Point p2(0,0,0);
    Point p3(0.001,0.001,0.001);
    Edge e2(&p2,&p3);

    if(e2.getLength()>.01){
        std::cout << "Failure in e2.getLength(): should be <.01 is: "
                  <<e2.getLength() << std::endl;
    };
}

void EdgeTester::testBadEdges()
{
    std::cout << "Execute EdgeTester::testBadEdges" << std::endl;

    // TODO: Writing a representative set of test cases for edges not formed correctly
    Point p0(0,0,0);
    Point p1(1,2,3);

    Edge e0(&p0, &p1);
    if(!e0.isValid()){
        std::cout << "Failure in e0.isValid. e0.isValid()="
                  << e0.isValid();
    }

    Edge e1(&p0, nullptr);
    if(e1.isValid()){
        std::cout << "Failure in e1.isValid. e1.isValid()="
                  << e1.isValid();
    }

    Edge e2(nullptr, &p0);
    if(e2.isValid()){
        std::cout << "Failure in e2.isValid. e2.isValid()="
                  << e2.isValid();
    }

    Edge e3(nullptr, nullptr);
    if(e3.isValid()){
        std::cout << "Failure in e3.isValid. e3.isValid()="
                  << e3.isValid();
    }

}
