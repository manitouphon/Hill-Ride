import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Window 2.2

import QtMultimedia 5.12

//-------------------------------------Root. Level: 1 (top)
Window {
    id: root
    width: 1366
    height: 768
    visible: true
    Component.onCompleted: {

        backgroundMusic.play()
    }

    function whenEnterGame() {
        //
        root.visible = false
    }

    //slot in QML that connected when gameplay is over:
    function gameplayOver() {
        mainMenu.visible = true

        backBtn.visible = false

        levelSelection.visible = false
        carSelect.visible = false
        option.visible = false
        instructions.visible = false

        root.visible = true
        console.log("Function 101")
    }

    property real sfxVolume: 0.5
    property real bmgVolume: 0.2

    signal enterGame(int gamemode)
    signal sfxChanged(double sfx)
    signal bmgChanged(double bmg)
    signal exitTheApp

    Audio {
        id: backgroundMusic
        volume: bgmSlider.value
        source: "qrc:/assets/resource/bgm.mp3"
        loops: Audio.Infinite
    }

    ////-------------------------------------Background Sound. Level: 2

    //-------------------------------------Backgound. Level: 2
    Image {
        id: background
        visible: true
        z: 2
        anchors.fill: parent
        fillMode: Image.Stretch
        source: "qrc:/assets/resource/background.png"

        //-------------------------------------BackButton. Level: 3

        //-------------------------------------MainMenu. Level: 3
        Rectangle {
            id: mainMenu
            x: 440
            y: 0
            color: "#00000000"
            anchors.fill: parent
            visible: true

            Row {
                id: btnRows
                x: 0
                y: -73
                width: 200
                height: 546
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                spacing: 4

                UiButton {
                    id: startBtn
                    width: 200
                    currentText: qsTr("Start")
                    height: 75
                    sfxVol: sfxSlider.value
                    anchors.verticalCenterOffset: -60
                    anchors.horizontalCenterOffset: 0
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    onButtonClicked: {
                        mainMenu.visible = false
                        backBtn.visible = true
                        levelSelection.visible = true
                    }
                }
                UiButton {
                    id: carSelectBtn
                    currentText: qsTr("Car Select")
                    anchors.verticalCenterOffset: 20
                    sfxVol: sfxSlider.value
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    onButtonClicked: {
                        mainMenu.visible = false
                        backBtn.visible = true
                        carSelect.visible = true
                    }
                }

                UiButton {
                    id: optionBtn
                    width: 200
                    height: 75
                    sfxVol: sfxSlider.value
                    anchors.verticalCenterOffset: 100
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter

                    currentText: qsTr("Option")
                    onButtonClicked: {
                        mainMenu.visible = false
                        backBtn.visible = true
                        option.visible = true
                    }
                }

                UiButton {
                    id: instructionBtn
                    anchors.verticalCenterOffset: 180
                    sfxVol: sfxSlider.value
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    currentText: qsTr("Instructions")
                    onButtonClicked: {
                        mainMenu.visible = false
                        backBtn.visible = true
                        instruction.visible = true
                    }
                }

                UiButton {
                    id: exitBtn
                    sfxVol: sfxSlider.value
                    anchors.verticalCenterOffset: 260
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter

                    currentText: qsTr("Exit")
                    onButtonClicked: {
                        exitTheApp()
                        Qt.quit()
                    }
                }
            }
        }

        //-------------------------------------LevelSelection. Level: 3
        Rectangle {
            id: levelSelection
            color: "#00000000"
            visible: false
            anchors.fill: parent

            Grid {
                id: grid
                anchors.fill: parent

                Row {
                    id: row
                    width: 200
                    height: 400
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter

                    UiButton {
                        id: easyBtn
                        sfxVol: sfxSlider.value
                        anchors.verticalCenterOffset: -30
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter

                        currentText: qsTr("Easy Level")
                        hBorderColor: "#006600"
                        hColor: "#99ff99"
                        onButtonClicked: {
                            enterGame(1)
                            whenEnterGame()
                        }
                    }

                    UiButton {
                        id: mediumBtn
                        sfxVol: sfxSlider.value
                        anchors.verticalCenterOffset: 50
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter

                        currentText: qsTr("Medium Level")
                        hBorderColor: "#802000"
                        hColor: "#ffb399"
                        onButtonClicked: {
                            enterGame(2)
                            whenEnterGame()
                        }
                    }

                    UiButton {
                        id: hardBtn
                        sfxVol: sfxSlider.value
                        anchors.verticalCenterOffset: 130
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter

                        currentText: qsTr("Hard Level")
                        hBorderColor: "#800000"
                        hColor: "#ff4d4d"
                        onButtonClicked: {
                            enterGame(3)
                            whenEnterGame()
                        }
                    }
                }
            }
        }

        //-------------------------------------CarSelection. Level: 3
        Rectangle {
            id: carSelect
            color: "#00000000"
            visible: false
            anchors.fill: parent

            GridView {
                id: gridView
                anchors.fill: parent

                Column {
                    id: column
                    width: 823
                    height: 102
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 57
                    anchors.verticalCenterOffset: 247
                    anchors.horizontalCenterOffset: 0
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter

                    UiButton {
                        id: selectLeftBtn
                        currentText: "<<"
                        scaling: 0.7
                        sfxVol: sfxSlider.value
                        anchors.horizontalCenterOffset: -190
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        onButtonClicked: {
                            image.visible = true
                            image1.visible = false
                        }
                    }

                    UiButton {
                        id: selectRightBtn
                        visible: true
                        scaling: 0.7
                        sfxVol: sfxSlider.value
                        currentText: ">>"
                        anchors.horizontalCenterOffset: 190
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        onButtonClicked: {
                            image.visible = false
                            image1.visible = true
                        }
                    }
                }

                Column {
                    id: imageStacks
                    width: 992
                    height: 373
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter

                    Image {
                        id: image
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        fillMode: Image.PreserveAspectFit
                        source: "qrc:/assets/resource/pixelCar2.png"
                    }

                    Image {
                        id: image1
                        visible: false
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        fillMode: Image.PreserveAspectFit
                        source: "qrc:/assets/resource/spr_bike_0.png"
                    }
                }
            }
        }

        //-------------------------------------Option. Level: 3
        Rectangle {
            id: option
            color: "#00000000"
            visible: false
            anchors.fill: parent

            Row {
                id: row1
                anchors.fill: parent

                Column {

                    id: soundEffectC
                    width: 1200
                    height: 150
                    anchors.verticalCenterOffset: -80
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenterOffset: 0
                    anchors.horizontalCenter: parent.horizontalCenter

                    Text {
                        id: element
                        text: qsTr("SFX volume:")
                        anchors.horizontalCenterOffset: -450
                        transformOrigin: Item.Left
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 40
                    }

                    Slider {
                        id: sfxSlider
                        width: 750
                        anchors.horizontalCenterOffset: 150
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        value: sfxVolume
                        onValueChanged: {
                            sfxVolume = sfxSlider.value
                            sfxChanged(value)
                        }
                    }
                }

                Column {
                    id: backgroundMusicC
                    width: 1200
                    height: 150
                    anchors.verticalCenterOffset: 80
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenterOffset: 0
                    anchors.horizontalCenter: parent.horizontalCenter

                    Text {
                        id: element1
                        text: qsTr("BGM Volume:")
                        anchors.horizontalCenterOffset: -450
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        font.pixelSize: 40
                    }

                    Slider {
                        id: bgmSlider
                        width: 750
                        anchors.horizontalCenterOffset: 150
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        value: bmgVolume
                        onValueChanged: {
                            bmgVolume = bgmSlider.value
                            bmgChanged(value)
                        }
                    }
                }
            }
        }


        //-------------------------------------Instruction. Level: 4
        Rectangle {
            id: instructions
            color: "#FFFFFFFF"
            visible: false
            anchors.fill: parent
            Text {
                id: instructionTextSet
                text: qsTr("Goal: get to the finish line
                            \n Controls:
                            \n [A] Reverse [S] Brake [D] Accelerate
                            \n [Left Shift] Nitro Boost
                            \n [Esc] Back")
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
        }



        UiButton {
            id: backBtn
            visible: false
            sfxVol: sfxSlider.value
            anchors.left: parent.left
            anchors.leftMargin: 60
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 60
            currentText: qsTr("Back")
            onButtonClicked: {
                mainMenu.visible = true

                backBtn.visible = false

                levelSelection.visible = false
                carSelect.visible = false
                option.visible = false
                instructions.visible = false
            }
        }
    }
}

/*##^##
Designer {
    D{i:3;invisible:true}D{i:10;invisible:true}D{i:16;invisible:true}D{i:24;invisible:true}
}
##^##*/
