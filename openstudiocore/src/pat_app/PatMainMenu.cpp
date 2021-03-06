/**********************************************************************
 *  Copyright (c) 2008-2013, Alliance for Sustainable Energy.  
 *  All rights reserved.
 *  
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *  
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *  
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include <pat_app/PatMainMenu.hpp>

#include <QMenu>

namespace openstudio{
  
namespace pat {

PatMainMenu::PatMainMenu(QWidget *parent) : 
  QMenuBar(parent)
{
  // File menu
  m_fileMenu = new QMenu(tr("&File"),this);
  addMenu(m_fileMenu);

  m_newAction = new QAction(tr("&New Project"), this);
  m_loadFileAction = new QAction(tr("&Open Project"), this);
  m_saveFileAction = new QAction(tr("&Save Project"), this);
  m_saveAsFileAction = new QAction(tr("Save Project &As"), this);
  m_clearAllResultsAction = new QAction(tr("&Clear All Results"), this);
  m_exportXmlAction = new QAction(tr("&Export XML Report"), this);
  m_scanForToolsAction = new QAction(tr("Scan for &Tools"), this);
  m_showToolsAction = new QAction(tr("Show Too&ls"), this);
  m_exitAction = new QAction(tr("E&xit"), this);

  m_exitAction->setShortcuts(QKeySequence::Quit);
  m_newAction->setShortcut(QKeySequence(QKeySequence::New));
  m_loadFileAction->setShortcut(QKeySequence(QKeySequence::Open));
  m_saveFileAction->setShortcut(QKeySequence(QKeySequence::Save));

  // DLM: actions which result in this menu being deleted should be queued
  bool isConnected = false;

  isConnected = connect(m_newAction, SIGNAL(triggered()), this, SIGNAL(newClicked()), Qt::QueuedConnection);
  Q_ASSERT(isConnected);

  isConnected = connect(m_loadFileAction, SIGNAL(triggered()), this, SIGNAL(loadFileClicked()), Qt::QueuedConnection);
  Q_ASSERT(isConnected);

  isConnected = connect(m_saveFileAction, SIGNAL(triggered()), this, SIGNAL(saveFileClicked()));
  Q_ASSERT(isConnected);

  isConnected = connect(m_saveAsFileAction, SIGNAL(triggered()), this, SIGNAL(saveAsFileClicked()));
  Q_ASSERT(isConnected);

  isConnected = connect(m_clearAllResultsAction, SIGNAL(triggered()), this, SIGNAL(clearAllResultsClicked()));
  Q_ASSERT(isConnected);

  isConnected = connect(m_exportXmlAction, SIGNAL(triggered()), this, SIGNAL(exportXmlClicked()));
  Q_ASSERT(isConnected);

  isConnected = connect(m_scanForToolsAction, SIGNAL(triggered()), this, SIGNAL(scanForToolsClicked()));
  Q_ASSERT(isConnected);

  isConnected = connect(m_showToolsAction, SIGNAL(triggered()), this, SIGNAL(showToolsClicked()));
  Q_ASSERT(isConnected);

  isConnected = connect(m_exitAction, SIGNAL(triggered()),this,SIGNAL(exitClicked()), Qt::QueuedConnection);
  Q_ASSERT(isConnected);

  m_fileMenu->addAction(m_newAction);
  m_fileMenu->addAction(m_loadFileAction);
  /*************************/
  m_fileMenu->addSeparator();
  m_fileMenu->addAction(m_saveFileAction);
  m_fileMenu->addAction(m_saveAsFileAction);
  /*************************/
  m_fileMenu->addSeparator();
  m_fileMenu->addAction(m_clearAllResultsAction);
  m_fileMenu->addAction(m_exportXmlAction);
  /*************************/
  m_fileMenu->addSeparator();
  m_fileMenu->addAction(m_scanForToolsAction);
  m_fileMenu->addAction(m_showToolsAction);
  /*************************/
  m_fileMenu->addSeparator();
  m_fileMenu->addAction(m_exitAction);

  // Preferences menu
  m_preferencesMenu = new QMenu(tr("&Preferences"),this);
  addMenu(m_preferencesMenu);

  m_changeMeasuresDir = new QAction(tr("&Change My Measures Directory"),this);

  isConnected = connect(m_changeMeasuresDir, SIGNAL(triggered()),this,SIGNAL(changeMeasuresClicked()));
  Q_ASSERT(isConnected);

  m_preferencesMenu->addAction(m_changeMeasuresDir);
  
  // Window menu
  m_windowMenu = new QMenu(tr("&Online BCL"),this);
  addMenu(m_windowMenu);

  m_openBclDlgAction = new QAction(tr("Find &Measures"),this);

  isConnected = connect(m_openBclDlgAction, SIGNAL(triggered()),this,SIGNAL(openBclDlgClicked()));
  Q_ASSERT(isConnected);

  m_windowMenu->addAction(m_openBclDlgAction);
  
  // Help menu
  m_helpMenu = new QMenu(tr("&Help"),this);
  addMenu(m_helpMenu);

  m_helpAction = new QAction(tr("PAT &Help"),this);
  m_aboutAction = new QAction(tr("&About"),this);

  isConnected = connect(m_helpAction, SIGNAL(triggered()),this,SIGNAL(helpClicked()));
  Q_ASSERT(isConnected);

  isConnected = connect(m_aboutAction, SIGNAL(triggered()),this,SIGNAL(aboutClicked()));
  Q_ASSERT(isConnected);

  m_helpMenu->addAction(m_helpAction);
  m_helpMenu->addAction(m_aboutAction);
}

PatMainMenu::~PatMainMenu()
{
}

void PatMainMenu::configure(bool haveCurrentProject)
{
  if (haveCurrentProject){

    m_saveFileAction->setEnabled(true);
    m_saveAsFileAction->setEnabled(true);
    m_clearAllResultsAction->setEnabled(true);
    m_exportXmlAction->setEnabled(true);

  }else{

    m_saveFileAction->setEnabled(false);
    m_saveAsFileAction->setEnabled(false);
    m_clearAllResultsAction->setEnabled(false);
    m_exportXmlAction->setEnabled(false);

  }
}

/**************************** SLOTS ****************************/

}

} // openstudio
