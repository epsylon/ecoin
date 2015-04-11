/*
    QTail is a simple graphical implementation of tail -f
    Copyright (C) 2012  Tazio Ceri <praise@praisenet.darktech.org>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "tail.h"

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMutexLocker>

Tail::Tail (QString fileName, QObject* parent): QThread(parent), abort(false), in(fileName), valid(true)
{
	if ( !in.open(QFile::ReadOnly | QFile::Text) )
	{
		valid = false;
	}
}

Tail::~Tail ()
{
	QMutexLocker lock(&mutex);
	abort = true;
	waiter.wakeOne();
}

void Tail::stopProcess()
{
	QMutexLocker lock(&mutex);
	abort = true;
	waiter.wakeOne();
}

void
Tail::goToPosition ()
{
	QStringList lines;
	QString line;
	
	while (  ! in.atEnd() )
	{
		line = in.readLine();
		lines.push_back ( in.readLine() );

            lines.pop_front();
	}
	foreach(line,lines)
        emit sendLine(line);
}

void Tail::checkLine()
{
	QMutexLocker locker(&mutex);
	waiter.wakeAll();
}


void
Tail::run ()
{
	QString line;	
	goToPosition();

	QMutexLocker lock(&mutex);
	forever 
	{
        waiter.wait(&mutex, 750);
		if (abort)
			return;
		while ( ! in.atEnd() )
		{	
			line = in.read(1024);
			if ( line.length() > 0 )
				emit sendLine(line);
		}
	}
}
