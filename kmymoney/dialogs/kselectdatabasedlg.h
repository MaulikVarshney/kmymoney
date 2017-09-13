/***************************************************************************
                          kselectdatabase.h
                             -------------------
    copyright            : (C) 2005 by Tony Bloomfield <tonybloom@users.sourceforge.net>

***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef KSELECTDATABASEDLG_H
#define KSELECTDATABASEDLG_H

// ----------------------------------------------------------------------------
// QT Includes

#include <QLabel>
#include <QUrl>

// ----------------------------------------------------------------------------
// KDE Includes

#include <QDialog>

// ----------------------------------------------------------------------------
// Project Includes

#include "ui_kselectdatabasedlg.h"
#include "storage/mymoneystoragesql.h"
#include "kguiutils.h"

class QDialogButtonBox;

class KSelectDatabaseDlg : public QDialog
{
  Q_OBJECT
public:
  explicit KSelectDatabaseDlg(int openMode, QUrl openURL = QUrl(), QWidget *parent = 0);
  ~KSelectDatabaseDlg();

  /**
   * Check whether we have required database drivers
   * @return - false, no drivers available, true, can proceed
   */
  bool checkDrivers();

  /**
   * Return URL of database
   * @return - pseudo-URL of database selected by user
   */
  const QUrl selectedURL();

  /**
   * Execute the database selection dialog
   * @return - as QDialog::exec()
   */
  int exec();

public slots:
  void slotDriverSelected(int idx);
  void slotHelp();

private:
  Ui::KSelectDatabaseDlg* m_widget;
  int m_mode;
  QUrl m_url;
  kMandatoryFieldGroup* m_requiredFields;
  bool m_sqliteSelected;
};

#endif
