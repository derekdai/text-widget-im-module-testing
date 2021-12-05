import QtQuick 2.0
import QtQuick.Controls 2.15

Rectangle {
    id: page
    width: 1280; height: 720

    TextEdit {
        id: textArea
        text: "Hello world!"
        anchors.fill: parent
    }
}
