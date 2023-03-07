// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick
import QtQuick.VirtualKeyboard

/*!
    \qmltype HideKeyboardKey
    \inqmlmodule QtQuick.VirtualKeyboard.Components
    \ingroup qmlclass
    \ingroup qtvirtualkeyboard-components-qml
    \ingroup qtvirtualkeyboard-key-types
    \inherits BaseKey

    \brief Hide keyboard key for keyboard layouts.

    This key hides the keyboard from the user when pressed.
*/

BaseKey {
    keyType: QtVirtualKeyboard.HideKeyboardKey
    functionKey: true
    highlighted: true
    onClicked: keyboard.doKeyboardFunction(QtVirtualKeyboard.HideInputPanel)
    keyPanelDelegate: keyboard.style ? keyboard.style.hideKeyPanel : undefined
}
