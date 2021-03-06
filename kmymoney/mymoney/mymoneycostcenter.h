/*
 * Copyright 2016-2019  Thomas Baumgart <tbaumgart@kde.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MYMONEYCOSTCENTER_H
#define MYMONEYCOSTCENTER_H

#include "kmm_mymoney_export.h"

// ----------------------------------------------------------------------------
// QT Includes

#include <QMetaType>
#include <QHash>

// ----------------------------------------------------------------------------
// Project Includes

#include "mymoneyobject.h"

/**
  * This class represents a tag within the MyMoney engine.
  */
class MyMoneyCostCenterPrivate;
class KMM_MYMONEY_EXPORT MyMoneyCostCenter : public MyMoneyObject
{
  Q_DECLARE_PRIVATE(MyMoneyCostCenter)

  KMM_MYMONEY_UNIT_TESTABLE

public:
  MyMoneyCostCenter();
  explicit MyMoneyCostCenter(const QString &id);

  MyMoneyCostCenter(const QString& id,
                    const MyMoneyCostCenter& other);
  MyMoneyCostCenter(const MyMoneyCostCenter & other);
  MyMoneyCostCenter(MyMoneyCostCenter && other);
  MyMoneyCostCenter & operator=(MyMoneyCostCenter other);
  friend void swap(MyMoneyCostCenter& first, MyMoneyCostCenter& second);

  ~MyMoneyCostCenter();

  QString name() const;
  void setName(const QString& val);

  /**
   * This member returns a possible number leading the name. If there
   * is no number infront of the name, then the full name will be returned
   * @sa name()
   */
  QString shortName() const;


  // Equality operator
  bool operator == (const MyMoneyCostCenter &) const;
  bool operator <(const MyMoneyCostCenter& right) const;

  /**
    * This method checks if a reference to the given object exists. It returns,
    * a @p true if the object is referencing the one requested by the
    * parameter @p id. If it does not, this method returns @p false.
    *
    * @param id id of the object to be checked for references
    * @retval true This object references object with id @p id.
    * @retval false This object does not reference the object with id @p id.
    */
  bool hasReferenceTo(const QString& id) const override;

  /**
   * @copydoc MyMoneyObject::referencedObjects
   */
  QSet<QString> referencedObjects() const override;

  static MyMoneyCostCenter null;
};

inline void swap(MyMoneyCostCenter& first, MyMoneyCostCenter& second) // krazy:exclude=inline
{
  using std::swap;
  swap(first.d_ptr, second.d_ptr);
}

inline MyMoneyCostCenter::MyMoneyCostCenter(MyMoneyCostCenter && other) : MyMoneyCostCenter() // krazy:exclude=inline
{
  swap(*this, other);
}

inline MyMoneyCostCenter & MyMoneyCostCenter::operator=(MyMoneyCostCenter other) // krazy:exclude=inline
{
  swap(*this, other);
  return *this;
}

//inline bool operator==(const MyMoneyCostCenter& lhs, const QString& rhs)
//{
//  return lhs.id() == rhs;
//}

/**
  * Make it possible to hold @ref MyMoneyCostCenter objects inside @ref QVariant objects.
  */
Q_DECLARE_METATYPE(MyMoneyCostCenter)

#endif
