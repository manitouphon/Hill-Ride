import QtQuick 2.0
import QtMultimedia 5.12


Item {



    id: uiButton

    property string currentText: qsTr("Start")
    property bool clicked: false
    property string color: "#BFBFBF"
    property string borderColor: "#E6E6E6"
    property string hColor: "#D9D9D9"
    property string hBorderColor: "#999999"
    property real scaling: 1.0

    property real sfxVol: 0.6

    signal buttonClicked

    width: 220
    height: 100
    scale: scaling

    SoundEffect {
        id: buttonClickSound
        source: "qrc:/assets/resource/click.wav"
        volume: sfxVol
    }
    SoundEffect {
        id: buttonHoverSound
        volume: sfxVol
        source: "qrc:/assets/resource/hover.wav"
    }

    Rectangle {
        id: rectangle
        width: 200
        height: 50
        color: color
        radius: 25
        border.color: borderColor
        border.width: 3
        anchors.centerIn: uiButton

        Text {
            id: displayText
            text: uiButton.currentText

            font.capitalization: Font.MixedCase
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 25
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: rectangle
        hoverEnabled: true
        onEntered: {
            rectangle.scale = 1.1
            rectangle.border.color = hBorderColor
            rectangle.color = hColor
            buttonHoverSound.play()
        }
        onExited: {
            rectangle.scale = 1
            rectangle.border.color = borderColor
            rectangle.color = color
        }
        onClicked: {
            buttonClicked()
            buttonClickSound.play()
        }
    }
}
