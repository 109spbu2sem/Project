import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import scene.module 1.0

ApplicationWindow
{
    property real lastX
    property real lastY

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
                    onTriggered:
                    {
                        statusBar.text = setStatusBar('New project opened')
                        loadButton.clicked()
                    }
                }

                MenuSeparator {}

                MenuItem
                {
                    text: qsTr("&Open existing...")
                    shortcut: "Ctrl+O"
                    onTriggered:
                    {
                        statusBar.text = qsTr('<font color="green">Project opened<font>')
                        loadButton.clicked()
                    }
                }

                MenuItem
                {
                    text: qsTr("&Save...")
                    shortcut: "Ctrl+S"
                    onTriggered:
                    {
                        statusBar.text = qsTr('<font color="green">Project saved<font>')
                        console.log("Save action triggered")
                    }
                }

                MenuItem
                {
                    text: qsTr("&Print")
                    shortcut: "Ctrl+P"
                    onTriggered:
                    {
                        statusBar.text = qsTr('<font color="green">Project printed<font>')
                        console.log("Print action triggered")
                    }
                }

                MenuItem
                {
                    text: qsTr("&Close project")
                    shortcut: "Ctrl+E"
                    onTriggered:
                    {
                        statusBar.text = qsTr('<font color="black">Project closed<font>')
                        console.log("Close action triggered")
                    }
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

                            onClicked:
                            {
                                addObjectDialog.close();
                                console.log("addObjectDialog -> Point");
                            }
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

                            onClicked:
                            {
                                addObjectDialog.close();
                                console.log("addObjectDialog -> Section");
                            }
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

                            onClicked:
                            {
                                addObjectDialog.close();
                                console.log("addObjectDialog -> Arc");
                            }
                        }
                    }
                }

                Button
                {
                    id: okAddObjectDialogButton

                    x: 10
                    y: 175
                    width: 90
                    height: 21

                    text: "OK"

                    onClicked:
                    {
                        addObjectDialog.close();
                        console.log("addObjectDialog -> Nothing");
                    }
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
            statusBar.text = fileUrl.toString()
            console.log('File added')
        }

    }

    GridLayout
    {
        columns: 2
        columnSpacing: 40

        x: 40
        y: 35
        width:  parent.width - 80
        height: parent.height - 80

        Rectangle
        {
            id: backgroundRect

            width: 860
            height: 640
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth: 600
            Layout.minimumHeight: 400

            color: "white"

            Canvas
            {
                id: mainCanvas

                anchors.fill: parent

                antialiasing: true

                onPaint:
                {
                    var ctx = getContext('2d')
                    ctx.fillStyle = "lightblue"
                    ctx.lineWidth = 1.5
                    ctx.beginPath()
                    ctx.moveTo(lastX, lastY)
                    lastX = mouseArea.mouseX
                    lastY = mouseArea.mouseY
                    ctx.lineTo(lastX, lastY)
                    ctx.stroke()
                    ctx.save()
                }

                MouseArea
                {
                    id: mouseArea

                    anchors.fill: parent

                    onPressed:
                    {
                        addObjectDialog.open()
                        lastX = mouseX
                        lastY = mouseY
                        //statusBar.text = gui.setStatusBar("Project changed")
                    }
                    onPositionChanged:
                    {
                        mainCanvas.requestPaint()
                        //mainCanvas.markDirty()
                    }
                }
            }
        }

        GridLayout
        {
            width: 300
            rows: 2
            rowSpacing: 40

            Rectangle
            {
                x: 0
                y: 0
                width: 300
                height: 500
                Layout.fillHeight: true

                TableView
                {
                    id: table
                    anchors.fill: parent
                    TableViewColumn
                    {
                        role: 'type'
                        title: "Type"
                        width: 95
                    }
                    TableViewColumn
                    {
                        role: 'name'
                        title: "Name"
                        width: 100
                    }
                    TableViewColumn
                    {
                        role: 'x'
                        title: "X"
                        width: 50
                    }
                    TableViewColumn
                    {
                        role: 'y'
                        title: "Y"
                        width: 50
                    }
                }
            }

            GridLayout
            {
                id: buttonGridLayout

                y: parent.height

                rows: 2
                columns: 2
                Layout.row: 2
                rowSpacing: 10
                columnSpacing: 10

                Item
                {
                    x: 0
                    y: -40
                    width: 145
                    height: 42

                    ToolButton
                    {
                        id: addObjectButton

                        activeFocusOnPress: true
                        onClicked: addObjectDialog.open()

                        width: 145
                        height: 42

                        text: "Add object"
                    }
                }

                Item
                {
                    x: 0
                    y: 12
                    width: 145
                    height: 42

                    ToolButton
                    {
                        id: addRuleButton

                        activeFocusOnPress: true
                        enabled: false

                        width: 145
                        height: 42

                        text: "Add rule"
                    }
                }

                Item
                {
                    x: 155
                    y: -40
                    width: 145
                    height: 42

                    ToolButton
                    {
                        id: loadButton

                        activeFocusOnPress: true
                        onClicked: {  fileDialog.open(); }

                        width: 145
                        height: 42

                        text: "Load..."
                    }
                }

                Item
                {
                    x: 155
                    y: 12
                    width: 145
                    height: 42

                    ToolButton
                    {
                        id: saveButton

                        width: 145
                        height: 42

                        text: "Save..."
                    }
                }
            }
        }
    }

    statusBar:
        StatusBar
        {
            RowLayout
            {
                Label
                {
                    id: statusBar

                    text: "Ready for work"
                }
            }
        }

    GUI
    {
        id: gui

        statusBar: statusBar.text
    }
}
