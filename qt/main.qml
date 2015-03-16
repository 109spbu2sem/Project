import QtQuick 2.3
import QtQuick.Controls 1.2

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
            title: qsTr("File")
            MenuItem
            {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem
            {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
}

Item
{
    id: workspace
    x: 38
    y: 27
    width: 870
    height: 651
    }

    ToolButton
    {
        id: addObjectButton
        x: 952
        y: 564
        width: 120
        height: 42
        text: "Add object"
        scale: 1
    }

    ToolButton
    {
        id: loadButton
        x: 952
        y: 636
        width: 120
        height: 42
        text: "Load..."
    }

    ToolButton
    {
        id: addRuleButton
        x: 1120
        y: 564
        width: 120
        height: 42
        text: "Add rule"
    }

    ToolButton
    {
        id: saveButton
        x: 1120
        y: 636
        width: 120
        height: 42
        text: "Save..."
    }

    Text {
        id: text1
        x: 952
        y: 27
        width: 288
        height: 506
        text: qsTr(" List of all objects:")
        font.bold: true
        horizontalAlignment: Text.AlignLeft
        wrapMode: Text.NoWrap
        textFormat: Text.PlainText
        font.pixelSize: 16
    }
}
