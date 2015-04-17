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

        Column
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth: 600
            Layout.minimumHeight: 400

            ToolBar
            {
                id: toolBar
                width: parent.width

                RowLayout
                {
                    spacing: 10

                    ToolButton
                    {
                        id: pointAddObjectDialogButton

                        width: 40
                        height: 40

                        Rectangle
                        {
                            width: parent.width
                            height: parent.height

                            color: "red"
                        }

                        Text
                        {
                            id:textPoint

                            y: 10
                            width: parent.width
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter

                            text: "Point"
                            color: 'white'
                        }

                        onClicked:
                        {
                            // gui.drawPoint();
                            console.log("toolBar -> Point");
                        }
                    }

                    ToolButton
                    {
                        id: sectionAddObjectDialogButton

                        width: 40
                        height: 40

                        Rectangle
                        {
                            width: parent.width
                            height: parent.height

                            color: "green"
                        }

                        Text
                        {
                            id: textSection

                            y: 10
                            width: parent.width
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter

                            text: "Section"
                            color: 'white'
                        }

                        onClicked:
                        {
                            // gui.drawSection();
                            console.log("toolBar -> Section");
                        }
                    }

                    ToolButton
                    {
                        id: arcAddObjectDialogButton

                        width: 40
                        height: 40

                        Rectangle
                        {
                            width: parent.width
                            height: parent.height

                            color: "blue"
                        }

                        Text
                        {
                            id: textArc

                            y: 10
                            width: parent.width
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter

                            text: "Arc"
                            color: 'white'
                        }

                        onClicked:
                        {
                            // gui.drawArc();
                            console.log("toolBar -> Arc");
                        }
                    }
                }
            }

            Rectangle
            {
                id: backgroundRect

                width: parent.width
                height: parent.height - 50
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
                        ctx.fillRect(lastX, lastY, 2, 2)
                        ctx.stroke()

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
                            mainCanvas.requestPaint()
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
