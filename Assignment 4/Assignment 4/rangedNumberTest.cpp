#include "TestHarness.h"
#include "RangedNumber.h"

extern const std::string PROJECT_PATH;

//stringification
#define STR(s) #s

TEST(cTor, ranged_number)
{
    ranged_number<short, 1, 12> grade;
	
    grade = 5;
	CHECK_EQUAL(grade, 5);
    CHECK_EQUAL(5, grade);
}

TEST(preIncrement, ranged_number)
{
    ranged_number<short, 1, 12> grade;
	
    grade = 5;
    CHECK_EQUAL(5, grade);
    
    ++grade;
    CHECK_EQUAL(6, grade);
}

TEST(preIncrementConstraint, ranged_number)
{
    ranged_number<short, 1, 12> grade;
	
    grade = 12;
    CHECK_EQUAL(12, grade);
    
    ++grade;
    CHECK_EQUAL(12, grade);
}

TEST(postIncrementConstraint, ranged_number)
{
    ranged_number<short, 1, 12> grade;
	
    grade = 12;
    CHECK_EQUAL(12, grade);
    
    grade++;
    CHECK_EQUAL(12, grade);
}

TEST(preDecrementConstraint, ranged_number)
{
    ranged_number<short, 1, 12> grade;
	
    grade = 1;
    CHECK_EQUAL(1, grade);
    
    --grade;
    CHECK_EQUAL(1, grade);
}

TEST(postDecrementConstraint, ranged_number)
{
    ranged_number<short, 1, 12> grade;
	
    grade = 1;
    CHECK_EQUAL(1, grade);
    
    grade--;
    CHECK_EQUAL(1, grade);
}

typedef ranged_number<int, 1, 12> Grade;

TEST(operatorPlus, ranged_number)
{
    Grade grade = 5;
	
    grade = grade + int(5);
    CHECK_EQUAL(10, grade);
	
    grade = grade + int(5);
    CHECK_EQUAL(12, grade);
}

TEST(operatorPlusEquals, ranged_number)
{
    Grade grade = 5;
	
    grade += 5;
    CHECK_EQUAL(10, grade);
	
    grade += 5;
    CHECK_EQUAL(12, grade);
	
}