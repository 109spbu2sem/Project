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
            title: qsTr("Project")
            MenuItem
            {
                text: qsTr("&Open new...")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem
            {
                text: qsTr("&Open existing...")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem
            {
                text: qsTr("&Save...")
                onTriggered: console.log("Save action triggered");
            }
            MenuItem
            {
                text: qsTr("&Print")
                onTriggered: console.log("Print action triggered");
            }
            MenuItem
            {
                text: qsTr("Close project")
                onTriggered: console.log("Close action triggered");
            }
        }

        Menu
        {
            title: qsTr("Settings")
            MenuItem
            {
                text: qsTr("&Change language")
            }
            MenuItem
            {
                text: qsTr("&Change GUI")
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
