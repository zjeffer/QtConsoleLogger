// Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
// Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "console.hpp"
#include "common.hpp"
#include <iostream>

// chrono literals
using namespace std::chrono_literals;

Console::Console(QWidget *parent) : QTextEdit(parent) {
	document()->setMaximumBlockCount(250);
	QPalette p = palette();
	p.setColor(QPalette::Base, Qt::black);
	p.setColor(QPalette::Text, Qt::green);
	setPalette(p);

	// set monospace font
	QFont f = font();
	f.setFamily("Monospace");
	f.setPointSize(11);
	setFont(f);
}

void Console::putData(const QByteArray &text) {
	insertPlainText(text.toStdString().c_str());

	QScrollBar *bar = verticalScrollBar();
	if (!bar->isSliderDown()) {
		// scroll to bottom if not dragging the scrollbar
		bar->setValue(bar->maximum());
	}
}

void Console::keyPressEvent(QKeyEvent *e) { Q_UNUSED(e); }

void Console::mousePressEvent(QMouseEvent *e) {
	Q_UNUSED(e);
	setFocus();
}

void Console::mouseDoubleClickEvent(QMouseEvent *e) { Q_UNUSED(e); }

void Console::contextMenuEvent(QContextMenuEvent *e) { Q_UNUSED(e); }
