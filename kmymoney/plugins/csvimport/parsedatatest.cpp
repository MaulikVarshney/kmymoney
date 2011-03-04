/***************************************************************************
                           parsedatatest.cpp
                          -------------------
    begin                : Sat Jan 01 2010
    copyright            : (C) 2010 by Allan Anderson
    email                : aganderson@ukonline.co.uk
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include "parsedatatest.h"

#include <QtTest/QtTest>
#include <QtCore/QString>

#include "csvutil.h"

QTEST_MAIN(ParseDataTest);

Parse* m_parseline;

ParseDataTest::ParseDataTest()
{
}

void ParseDataTest::init()
{
  m_parseline = new Parse;
}

void ParseDataTest::cleanup()
{
  delete m_parseline;
}

void ParseDataTest::parseSplitString()
{
  for (int i = 0; i <= 3; i++)  { //        All four delimiters should produce same result
    m_parseline->setFieldDelimiterIndex(i);
    m_parseline->setFieldDelimiterCharacter(i);

    QString input = "abc,defgh,";//  When this string is QString::split(), two strings
    //  ....will result if ',' is the field delimiter.
    //      This is not good.
    input.prepend('"');//            make input string quoted
    input.append('"');
    QStringList expected;
    expected << "abc,defgh,";
    QVERIFY(m_parseline->parseLine(input) == expected);// if parseLine() detects the condition,
  }                                                   // ...it rebuilds the string
}

void ParseDataTest::parse_data()
{
}

void ParseDataTest::cleanupTestCase()
{
}

void ParseDataTest::testConstructor()
{
}

void ParseDataTest::testConstructor_data()
{
}

void ParseDataTest::testDefaultConstructor()
{
}

void ParseDataTest::testDefaultConstructor_data()
{
}

void ParseDataTest::initTestCase()
{
}

void ParseDataTest::initTestCase_data()
{
}
