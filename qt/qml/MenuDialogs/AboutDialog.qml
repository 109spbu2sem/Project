import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2

Dialog
{
    title: qsTr("About")
    width: 525
    height: 360


    Rectangle
    {
        x: 0
        y: 0
        width: parent.width - 25
        height: parent.height - 60
        anchors.centerIn: parent

        Text
        {
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
