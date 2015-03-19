import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow
{
    id: about
    title: qsTr("About")

    visible: true

    Rectangle
    {
        x: 0
        y: 0
        width: 500
        height: 300

        Text {
            id: text1
            x: 8
            y: 8
            width: 484
            height: 284
            text: qsTr("Hello, world!")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            textFormat: Text.RichText
            font.pixelSize: 12
        }
    }
}
