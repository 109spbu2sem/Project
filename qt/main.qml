import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2

ApplicationWindow
{
    visible: true

    width: 1280
    height: 720

    title: qsTr("Paint")

    menuBar: MenuBar
    {
    Menu
    {
        title: qsTr("Project")
        MenuItem
        {
            text: qsTr("&Open new...")
            shortcut: "Ctrl+Shift+N"
            onTriggered: console.log("Open action triggered");
        }
        MenuSeparator {}
        MenuItem
        {
            text: qsTr("&Open existing...")
            shortcut: "Ctrl+O"
            onTriggered: console.log("Open action triggered");
        }
        MenuItem
        {
            text: qsTr("&Save...")
            shortcut: "Ctrl+S"
            onTriggered: console.log("Save action triggered");
        }
        MenuItem
        {
            text: qsTr("&Print")
            shortcut: "Ctrl+P"
            onTriggered: console.log("Print action triggered");
        }
        MenuItem
        {
            text: qsTr("Close project")
            shortcut: "Ctrl+E"
            onTriggered: console.log("Close action triggered");
        }
    }

    Menu
    {
        title: qsTr("Settings")
        MenuItem
        {
            text: qsTr("&Change language")
            shortcut: "Alt+L"
        }
        MenuItem
        {
            text: qsTr("&Change GUI")
            shortcut: "Alt+G"
        }
    }

    Menu
    {
        title: qsTr("Help")
        MenuItem
        {
            text: qsTr("&About Paint")
        }
        MenuItem
        {
            text: qsTr("&Send feedback")
        }
    }
}

Item
{
    id: workspace
    x: -291
    y: -369
    width: 1616
    height: 1344
}

FileDialog {
    id: fileDialog
    title: "Please choose a file"
    onAccepted:
    {
        console.log("You chose: " + fileDialog.fileUrls)
    }
    onRejected:
    {
        console.log("Canceled")
    }
}

ToolButton
{
    id: addObjectButton
    x: 952
    y: 564
    width: 120
    height: 42
    text: "Add object"
    activeFocusOnPress: true
}

ToolButton
{
    id: loadButton
    x: 952
    y: 636
    width: 120
    height: 42
    text: "Load..."
    activeFocusOnPress: true
    onClicked: fileDialog.open()
}

ToolButton
{
    id: addRuleButton
    x: 1120
    y: 564
    width: 120
    height: 42
    text: "Add rule"
    activeFocusOnPress: true
}

ToolButton
{
    id: saveButton
    x: 1120
    y: 636
    width: 120
    height: 42
    text: "Save..."
    activeFocusOnPress: true
}

Text
{
    id: text1
    x: 952
    y: 27
    width: 288
    height: 506
    text: " List of all objects:"
    enabled: true
    font.bold: true
    horizontalAlignment: Text.AlignLeft
    wrapMode: Text.NoWrap
    textFormat: Text.PlainText
    font.pixelSize: 16
}

Rectangle
{
    id: rectangle1
    x: 38
    y: 27
    width: 870
    height: 651
    color: "#ffffff"
}
}
