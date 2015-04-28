import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtQuick.XmlListModel 2.0
import gui.module 1.0

ApplicationWindow
{
    signal newPointAdded(double x, double y)

    property double lastX
    property double lastY

    property double firstX
    property double firstY
    property bool usingFirstCoords

    property int n
    property int k

    property string fileUrlLoad

    function draw(n)
    {
        switch (n)
        {
            case 1:
            {
                addNewPoint(lastX, lastY)
                newPointAdded(lastX, lastY)
            }
            case 2:
                //addNewSection()
            case 3:
                //addNewArc()
            default:
                console.log("n is undefined")
        }

    }

    function addNewPoint(x, y)
    {
        console.log('adding new point:' + x + ' ' + y)
        lastX = x
        lastY = y
        k = 1
        mainCanvas.requestPaint()
        statusBar.text = qsTr("<font color = 'green'> New point added <font>")
    }

    function addNewSection(a_x, a_y, b_x, b_y)
    {
        console.log('adding new section:' + a_x + ' ' + a_y + ' to ' + b_x + ' ' + b_y)
        firstX = a_x
        firstY = a_y
        lastX  = b_x
        lastY  = b_y
        k = 2
        mainCanvas.requestPaint()
        statusBar.text = qsTr("<font color = 'green'> New point added <font>")
    }

    function drawPoint(ctx, lastX, lastY)
    {
        ctx.fillStyle = "black"
        ctx.lineWidth = 1.5
        ctx.beginPath()
        ctx.moveTo(lastX, lastY)
        ctx.fillRect(lastX, lastY, 3, 3)
        ctx.stroke()
    }

    function drawSection(ctx, firstX, firstY, lastX, lastY)
    {
        ctx.fillStyle = "black"
        ctx.lineWidth = 1.5
        ctx.moveTo(firstX, firstY)
        ctx.beginPath()
        ctx.lineTo(lastX, lastY)
        ctx.stroke()
    }

    // -----------------------------------------------------------------------
    // -----------------------------------------------------------------------
    // -----------------------------------------------------------------------
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
        id: loadFileDialog
        title: qsTr("Select a file")
        selectMultiple: false
        selectFolder: false
        nameFilters: [ "All files (*)" ]
        selectedNameFilter: "All files (*)"
        onAccepted:
        {
            statusBar.text = fileUrl.toString()
            fileUrlLoad = fileUrl.toString()
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
                            n = 1
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
                            n = 2
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
                            n = 3
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
                        switch (k)
                        {
                        case 1:
                            drawPoint(ctx, lastX, lastY)
                        case 2:
                            drawSection(ctx, firstX, firstY, lastX, lastY)
                        case 3:
                            //  drawEllipse(ctx)
                        default:
                            console.log("k is undefined")
                        }
                    }

                    MouseArea
                    {
                        id: mouseArea

                        anchors.fill: parent

                        hoverEnabled: true

                        onPressed:
                        {
                            lastX = parseInt(mouseX, 10)
                            lastY = parseInt(mouseY, 10)

                            if(!((n == 1) || (n == 2) || (n == 3)))
                            {
                                n = 1
                                usingFirstCoords = false
                            }

                            if (n == 1)
                                draw(n);
                            else
                            {
                                firstX = parseInt(mouseX, 10)
                                firstY = parseInt(mouseY, 10)
                                usingFirstCoords = true
                                console.log('firstX = ' + firstX)
                                console.log('firstY = ' + firstY)
                            }
                        }

                        onPositionChanged:
                        {
                            positionInfo.text = "x: " + parseInt(mouseX, 10) + "\n" + "y: " + parseInt(mouseY, 10)

                            if (n == 2 && usingFirstCoords)
                                draw(n);
                        }
                    }

                    Text
                    {
                        id: positionInfo

                        anchors.bottom: parent.bottom
                        anchors.right:  parent.right

                        text: "x: 0\ny: 0"
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

                    model:
                        XmlListModel
                        {
                            id: projectModel
                            source: fileUrlLoad
                            query: "/list/primitive"
                            XmlRole { name: "id"; query: "id/string()" }
                            XmlRole { name: "type"; query: "type/string()" }
                            XmlRole { name: "x1"; query: "x1/string()" }
                            XmlRole { name: "y1"; query: "y1/string()" }
                            XmlRole { name: "x2"; query: "x2/string()" }
                            XmlRole { name: "y2"; query: "y2/string()" }
                            XmlRole { name: "radius"; query: "radius/string()" }
                            XmlRole { name: "color"; query: "color/string()" }
                        }

                    TableViewColumn
                    {
                        role: "id"
                        title: "id"
                        width: 50
                    }
                    TableViewColumn
                    {
                        role: "type"
                        title: "Type"
                        width: 75
                    }
                    TableViewColumn
                    {
                        role: "x1"
                        title: "X1"
                        width: 60
                    }
                    TableViewColumn
                    {
                        role: "y1"
                        title: "Y1"
                        width: 60
                    }
                    TableViewColumn
                    {
                        role: "x2"
                        title: "X2"
                        width: 60
                    }
                    TableViewColumn
                    {
                        role: "y2"
                        title: "Y2"
                        width: 60
                    }
                    TableViewColumn
                    {
                        role: "radius"
                        title: "Radius"
                        width: 75
                    }
                    TableViewColumn
                    {
                        role: "color"
                        title: "Color"
                        width: 60
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
                        enabled: false

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
                        onClicked: {  loadFileDialog.open(); }

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
