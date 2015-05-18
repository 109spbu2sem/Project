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
    signal newSegmentAdded(double a_x, double a_y, double b_x, double b_y)

    property double x
    property double y
    property double a_x
    property double a_y
    property double b_x
    property double b_y

    property double lastX
    property double lastY

    property double firstX
    property double firstY
    property bool usingFirstCoords

    property int n
    property int k

    property string fileUrlLoad

    //  Points  ================================================================================================================
    function addNewPoint(x, y)
    {
        lastX = x
        lastY = y
        console.log("requesting point drawing")
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
        console.log("drawPoint()")
    }

    //  Segments  ==============================================================================================================
    function addNewSegment(a_x, a_y, b_x, b_y)
    {
        firstX = a_x
        firstY = a_y
        lastX  = b_x
        lastY  = b_y
        console.log("requesting segment drawing")
        mainCanvas.requestPaint()
        statusBar.text = qsTr("<font color = 'green'> New segment added <font>")
    }

    function drawLine(ctx, firstX, firstY, lastX, lastY)
    {
        ctx.fillStyle = "black"
        ctx.lineWidth = 1
        ctx.beginPath()
        ctx.moveTo(firstX + 1, firstY + 1)
        ctx.lineTo(lastX + 1, lastY + 1)
        ctx.stroke()
        console.log("drawSegment()")
    }

    //  Delete  ================================================================================================================
    function deletePoint(ctx, lastX, lastY)
    {
        //  now works as Eraser, should delete selected element and redraw() whole mainCanvas
        ctx.beginPath()
        ctx.clearRect(lastX - 1, lastY - 1, 6, 6)
        ctx.stroke()
    }

    //  Connections  ===========================================================================================================
    Connections
    {
        target: gui
        onNewPointAdded: addNewPoint(x, y)
        onNewSegmentAdded: addNewSegment(a_x, a_y, b_x, b_y)
    }


    //  ====================================================================================
    //  ====================================================================================
    //  ====================================================================================
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
                title: qsTr("Edit")

                MenuItem
                {
                    text: qsTr("&Undo")
                    shortcut: "Ctrl+Z"
                }

                MenuItem
                {
                    text: qsTr("&Redo")
                    shortcut: "Ctrl+Shift+Z"
                }

                MenuSeparator{}

                Menu
                {
                    title: qsTr("Additional")

                    MenuItem
                    {
                        text: qsTr("&empty")
                        enabled: false
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
            // fileAdded()  //  signal, waiting for request from Core to draw all elements
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

                        activeFocusOnPress: true

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
                        id: segmentAddObjectDialogButton

                        width: 40
                        height: 40

                        activeFocusOnPress: true

                        Rectangle
                        {
                            width: parent.width
                            height: parent.height

                            color: "green"
                        }

                        Text
                        {
                            id: textSegment

                            y: 10
                            width: parent.width
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter

                            text: "Segment"
                            color: 'white'
                        }

                        onClicked:
                        {
                            n = 2
                            console.log("toolBar -> Segment");
                        }
                    }

                    ToolButton
                    {
                        id: circleAddObjectDialogButton

                        width: 40
                        height: 40

                        activeFocusOnPress: true

                        Rectangle
                        {
                            width: parent.width
                            height: parent.height

                            color: "blue"
                        }

                        Text
                        {
                            id: textCircle

                            y: 10
                            width: parent.width
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter

                            text: "Circle"
                            color: 'white'
                        }

                        onClicked:
                        {
                            n = 3
                            console.log("toolBar -> Circle");
                        }
                    }

                    ToolButton
                    {
                        id: deletePointButton

                        width: 40
                        height: 40

                        activeFocusOnPress: true

                        Rectangle
                        {
                            width: parent.width
                            height: parent.height

                            color: "orange"
                        }

                        Text
                        {
                            id: textDelete

                            y: 10
                            width: parent.width
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter

                            text: "Delete"
                            color: 'white'
                        }

                        onClicked:
                        {
                            n = 4
                            console.log("toolBar -> Delete");
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

                        if (n == 1)
                        {
                            drawPoint(ctx, lastX, lastY)
                        }
                        else if (n == 2)
                        {
                            if (usingFirstCoords == true)
                            {
                                drawPoint(ctx, firstX, firstY)
                            }
                            else
                            {
                                drawLine(ctx, firstX, firstY, lastX, lastY)
                                drawPoint(ctx, lastX, lastY)
                            }
                        }
                        else if (n == 3)
                        {
                            //  drawEllipse(ctx)
                        }
                        else if (n == 4)
                        {
                            deletePoint(ctx, lastX, lastY)
                        }
                    }

                    MouseArea
                    {
                        id: mouseArea

                        anchors.fill: parent

                        hoverEnabled: true

                        onPressed:
                        {
                            if(!((n == 1) || (n == 2) || (n == 3) || (n == 4)))
                            {
                                pointAddObjectDialogButton.clicked()
                            }

                            lastX = parseInt(mouseX, 10)
                            lastY = parseInt(mouseY, 10)

                            if (n == 1)
                            {
                                addNewPoint(lastX, lastY)
                                newPointAdded(lastX, lastY)
                            }
                            else if (n == 2)
                            {
                                if (usingFirstCoords != true)
                                {
                                    firstX = parseInt(mouseX, 10)
                                    firstY = parseInt(mouseY, 10)
                                    addNewPoint(firstX, firstY)
                                    usingFirstCoords = true
                                }
                                else
                                {
                                    addNewSegment(firstX, firstY, lastX, lastY)
                                    newSegmentAdded(firstX, firstY, lastX, lastY)
                                    usingFirstCoords = false
                                }
                            }
                            else if (n == 3)
                            {
                                //
                            }
                            else if (n == 4)
                            {
                                mainCanvas.requestPaint()
                            }
                        }

                        onPositionChanged:
                        {
                            if (mouseArea.pressed)
                            {
                                if (n == 4)
                                {
                                    lastX = parseInt(mouseX, 10)
                                    lastY = parseInt(mouseY, 10)
                                    mainCanvas.requestPaint()
                                }
                            }
                            positionInfo.text = "x: " + parseInt(mouseX, 10) + "\n" + "y: " + parseInt(mouseY, 10)
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
                        XmlListModel  //  Not actual for this moment
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

                        movable: false

                        width: 50
                    }
                    TableViewColumn
                    {
                        role: "type"
                        title: "Type"

                        movable: false

                        width: 75
                    }
                    TableViewColumn
                    {
                        role: "x1"
                        title: "X1"

                        movable: false

                        width: 60
                    }
                    TableViewColumn
                    {
                        role: "y1"
                        title: "Y1"

                        movable: false

                        width: 60
                    }
                    TableViewColumn
                    {
                        role: "x2"
                        title: "X2"

                        movable: false

                        width: 60
                    }
                    TableViewColumn
                    {
                        role: "y2"
                        title: "Y2"

                        movable: false

                        width: 60
                    }
                    TableViewColumn
                    {
                        role: "radius"
                        title: "Radius"

                        movable: false

                        width: 75
                    }
                    TableViewColumn
                    {
                        role: "color"
                        title: "Color"

                        movable: false

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
