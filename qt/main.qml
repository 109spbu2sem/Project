import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import scene.module 1.0

ApplicationWindow
{
    property int xpos
    property int ypos

    visible: true

    title: qsTr("Paint")

    x: 60
    y: 80
    width: 1280
    height: 720

    menuBar:
        MenuBar
        {
            Menu
            {
                title: qsTr("Project")

                MenuItem
                {
                    text: qsTr("&Open new...")
                    shortcut: "Ctrl+Shift+N"
                    onTriggered: loadButton.clicked();
                }

                MenuSeparator {}

                MenuItem
                {
                    text: qsTr("&Open existing...")
                    shortcut: "Ctrl+O"
                    onTriggered: loadButton.clicked();
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
                    onTriggered: ;
                }

                MenuItem
                {
                    text: qsTr("&Send feedback")
                }
            }
        }

    Dialog
    {
        id: addObjectDialog

        contentItem:
            Rectangle
            {
                implicitWidth: 340
                implicitHeight: 200

                color: "lightblue"

                Text
                {
                    id: title

                    x: 10
                    y: 5

                    text: "Choose type of object"
                    color: "white"
                    font.bold: true
                    style: Text.Raised
                }

                Grid
                {
                    id: objectChoose

                    x: 10
                    y: 25

                    Row
                    {
                        spacing: 10

                        ToolButton
                        {
                            id: pointAddObjectDialogButton

                            width: 100
                            height: 130

                            Rectangle
                            {
                                width: 100
                                height: 100

                                color: "red"
                            }

                            Text
                            {
                                id:textPoint

                                y: 100
                                width: 100
                                height: 30
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter

                                text: "Point"
                            }

                            onClicked: {  addObjectDialog.close(); console.log("addObjectDialog -> Point");  }
                        }

                        ToolButton
                        {
                            id: sectionAddObjectDialogButton

                            width: 100
                            height: 130

                            Rectangle
                            {
                                width: 100
                                height: 100

                                color: "green"
                            }

                            Text
                            {
                                id: textSection

                                y: 100
                                width: 100
                                height: 30
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter

                                text: "Section"
                            }

                            onClicked: {  addObjectDialog.close(); console.log("addObjectDialog -> Section");  }
                        }

                        ToolButton
                        {
                            id: arcAddObjectDialogButton

                            width: 100
                            height: 130

                            Rectangle
                            {
                                width: 100
                                height: 100

                                color: "blue"
                            }

                            Text
                            {
                                id: textArc

                                y: 100
                                width: 100
                                height: 30
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter

                                text: "Arc"
                            }

                            onClicked: {  addObjectDialog.close(); console.log("addObjectDialog -> Arc");  }
                        }
                    }
                }

                Button
                {
                    id: okAddObjectDialogButton
                    onClicked: {  addObjectDialog.close(); console.log("addObjectDialog -> Nothing");  }

                    x: 10
                    y: 175
                    width: 90
                    height: 21

                    text: "OK"
                }
            }
        }

    FileDialog
    {
        id: fileDialog
        title: qsTr("Select a file")
        selectMultiple: false
        selectFolder: false
        nameFilters: [ "All files (*)" ]
        selectedNameFilter: "All files (*)"
        onAccepted:
        {
            statusBar.text = fileUrl.toString().add("file://", "")
            console.log('File added');  }

    }

    MainForm
    {
        width: parent.width - 80
        height: parent.height - 80
    }

    statusBar:
        StatusBar
        {
            RowLayout
            {
                anchors.fill: parent

                Label
                {
                    id: statusBar

                    text: "Ready for work"
                }
            }
        }
}
