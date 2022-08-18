// Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
// Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#pragma once

#include "common.hpp"
#include <QScrollBar>
#include <QTextEdit>

class Console : public QTextEdit {

	Q_OBJECT

  public:
	explicit Console(QWidget *parent = nullptr);

  public slots:
	void putData(const QByteArray &text);

  signals:
	void getData(const QByteArray &text);

  protected:
	void keyPressEvent(QKeyEvent *e) override;
	void mousePressEvent(QMouseEvent *e) override;
	void mouseDoubleClickEvent(QMouseEvent *e) override;
	void contextMenuEvent(QContextMenuEvent *e) override;
};
