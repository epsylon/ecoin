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


#ifndef TAIL_H
#define TAIL_H

#include <QThread>
#include <QMutex>
#include <QFile>
#include <QWaitCondition>
#include <QTimer>

class Tail: public QThread
{
	Q_OBJECT
	
	bool abort;
	QMutex mutex;
	
	QFile in;
	
	bool valid;
	QString _error;
	QWaitCondition waiter;

	void goToPosition();

signals:
	void sendLine(QString line);
	void Error (QString arg);
	
private slots:
	void checkLine();

public slots:
	void stopProcess();

public:
	Tail (QString fileName, QObject* parent);
	virtual void run();
	bool isValid() const { return valid; }
	QString error() const { return _error; }
	virtual ~Tail ();
};

#endif // TAIL_H
