/*
    KSysGuard, the KDE System Guard

	Copyright (c) 1999, 2000 Chris Schlaeger <cs@kde.org>
	Copyright (c) 2006 John Tapsell <john.tapsell@kde.org>

    This program is free software; you can redistribute it and/or
    modify it under the terms of version 2 of the GNU General Public
    License as published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#ifndef _ProcessController_h_
#define _ProcessController_h_

#include <QWidget>
#include <QAbstractItemModel>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QList>
#include <QProcess>


#include <kapplication.h>

#include <SensorDisplay.h>

class KSysGuardProcessList;
/**
 * This widget implements a process list page. Besides the process
 * list which is implemented as a ProcessList, it contains two
 * comboxes and two buttons.  The combo boxes are used to set the
 * update rate and the process filter.  The buttons are used to force
 * an immediate update and to kill a process.
 */
class ProcessController : public KSGRD::SensorDisplay
{
	Q_OBJECT

public:
	ProcessController(QWidget* parent, const QString& title, SharedSettings *workSheetSettings);
	virtual ~ProcessController() { }

	/* Functions for SensorDisplay*/
	
	bool restoreSettings(QDomElement& element);

	bool saveSettings(QDomDocument& doc, QDomElement& element);

	virtual void timerTick()
	{
	}

	virtual bool addSensor(const QString&, const QString&, const QString&, const QString&);

	virtual void sensorError(int, bool err);

	void configureSettings() { }

	virtual bool hasSettingsDialog() const
	{
		return false;
	}
private:
	KSysGuardProcessList *mProcessList;
};

#endif
