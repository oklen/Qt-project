///****************************************************************************
//**
//** Copyright (C) 2017 The Qt Company Ltd.
//** Contact: https://www.qt.io/licensing/
//**
//** This file is part of the examples of the Qt Toolkit.
//**
//** $QT_BEGIN_LICENSE:BSD$
//** Commercial License Usage
//** Licensees holding valid commercial Qt licenses may use this file in
//** accordance with the commercial license agreement provided with the
//** Software or, alternatively, in accordance with the terms contained in
//** a written agreement between you and The Qt Company. For licensing terms
//** and conditions see https://www.qt.io/terms-conditions. For further
//** information use the contact form at https://www.qt.io/contact-us.
//**
//** BSD License Usage
//** Alternatively, you may use this file under the terms of the BSD license
//** as follows:
//**
//** "Redistribution and use in source and binary forms, with or without
//** modification, are permitted provided that the following conditions are
//** met:
//**   * Redistributions of source code must retain the above copyright
//**     notice, this list of conditions and the following disclaimer.
//**   * Redistributions in binary form must reproduce the above copyright
//**     notice, this list of conditions and the following disclaimer in
//**     the documentation and/or other materials provided with the
//**     distribution.
//**   * Neither the name of The Qt Company Ltd nor the names of its
//**     contributors may be used to endorse or promote products derived
//**     from this software without specific prior written permission.
//**
//**
//** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
//**
//** $QT_END_LICENSE$
//**
//****************************************************************************/

import QtQuick 2.9
import QtQuick.Controls.Material 2.2
import QtQuick.Window 2.3
import QtQuick.Controls 2.2
import FileIO 1.0
//Page {
//    width: 1920
//    height: 1024
//    font.family: "Times New Roman"

//    TextField {
//    onReleased: {input1.selectAll();}
//    x:10
//    y:597
//    id: input1
//    width: 160
//    placeholderText: qsTr("Input")
//    ComboBox {
//        id: comboBox
//        x: 162
//        y: 0
//        width: 40
//        height: 40
//        onDownChanged: {menu.popup(0,40)}
//    }        Menu {
//        x:10
//        y:595
//        id: menu
//        width: 160

//        contentHeight: 400
//        leftPadding: 5
//        title: qsTr("Advanced")

//        //      Action { id:a1;text: qsTr("Tool Bar"); checkable: true }
//        //      Action { text: qsTr("Side Bar"); checkable: true; checked: true }
//        //      Action { text: qsTr("Status Bar"); checkable: true; checked: true ;}
//        Component.onCompleted: {
//            var a = "f"
//            while (a != "") {
//                a = myFile.read()
//                console.log(a)
//                if (a != "") {
//                    var newObject = Qt.createQmlObject(
//                                "import QtQuick.Controls 2.3;Action{

//checkable: true;
//checked: true}", parent, "dynamicSnippet")
//                    newObject.text = a
//                    menu.addAction(newObject)
//                } else {
//                    myFile.close()
//                }
//            }
//        }

//        bottomPadding: 2

//        delegate: MenuItem {

//            height: 40
//            id: menuItem
//            width: 150
//            contentItem: Row {

//                height: 20
//                topPadding: 0
//                MouseArea {
//                    width: 100
//                    height: 40
//                    id: mouseArea1
//                    Text {
//                        width: 100
//                        height: 40
//                        text: menuItem.text
//                        font: menuItem.font
//                        opacity: enabled ? 1.0 : 0.3
//                        color: menuItem.highlighted ? "#ffffff" : "#21be2b"
//                        horizontalAlignment: Text.AlignLeft
//                        elide: Text.ElideLeft
//                    }
//                    onReleased: {
//                        input1.text = menu.actionAt(menu.currentIndex).text
//                    }
//                }
//                MouseArea {
//                    width: 40
//                    height: 40
//                    onClicked: {
//                        console.log(menu.count)

//                        menu.removeAction(menu.actionAt(menu.currentIndex))
//                    }

//                    Image {
//                        autoTransform: true
//                        verticalAlignment: Image.AlignTop
//                        width: 20
//                        height: 20
//                        source: "../../../../../../../../../../root/menu/exit.jpg"
//                    }
//                }
//            }
//            indicator: Item {
//                implicitWidth: 40
//                implicitHeight: 40
//                anchors.left: contentItem.right
//            }

//            background: Rectangle {
//                implicitWidth: 150
//                implicitHeight: 40
//                opacity: enabled ? 1 : 0.3
//                color: menuItem.highlighted ? "#21be2b" : "transparent"
//            }
//        }
//    }}

//    FileIO {
//        id: myFile
//        source: "/root/good.txt"
//        onError: console.log(msg)
//    }



//    Button {
//        id: button
//        x: 0
//        y: -5
//        width: 115
//        height: 48
//        text: qsTr("File")
//    }

//    Button {
//        id: button1
//        x: 115
//        y: -5
//        width: 115
//        height: 48
//        text: qsTr("Figure")
//    }

//    Button {
//        id: button2
//        x: 230
//        y: -5
//        width: 115
//        height: 48
//        text: qsTr("Control")
//    }

//    TabBar {
//        x: 0
//        y: 35
//        width: 200
//        height: 48
//        Material.accent: Material.Blue
//        TabButton {
//            id: tabutton1
//            x: 0
//            y: 0
//            text: "Figure A"
//        }

//        TabButton {
//            id: tabutton2
//            x: 105
//            y: 0
//            text: "Figure B"
//        }
//    }

//    Flow {
//        id: flow1
//        x: 0
//        y: 48
//        width: 324
//        height: 328
//    }

//    CheckDelegate {
//        id: checkDelegate2
//        x: 0
//        y: 131
//        text: qsTr("Enable Function")

//        Slider {
//            Material.accent: Material.Blue
//            id: slider
//            x: 69
//            y: 43
//            padding: 5
//            font.pixelSize: 8
//            value: 0.5
//        }
//    }

//    Label {
//        id: label
//        x: 14
//        y: 94
//        width: 74
//        height: 31
//        color: "#4b81f2"
//        text: qsTr("Configure")
//        font.pointSize: 14
//        renderType: Text.NativeRendering
//        styleColor: "#ca0c0c"
//    }

//    Text {
//        id: text2
//        x: 17
//        y: 185
//        color: "#ffffff"
//        text: qsTr("Speed")
//        font.pixelSize: 16
//    }

//    Label {
//        id: label1
//        x: 17
//        y: 222
//        text: qsTr("Paramter1")
//        font.pointSize: 13
//    }

//    Flow {
//        id: flow2
//        x: 0
//        y: 48
//        width: 324
//        height: 328
//    }

//    Label {
//        id: label2
//        x: 14
//        y: 385
//        width: 74
//        height: 31
//        color: "#4b81f2"
//        text: qsTr("Status")
//        styleColor: "#ca0c0c"
//        renderType: Text.NativeRendering
//        font.pointSize: 14
//    }

//    Label {
//        id: label3
//        x: 17
//        y: 282
//        width: 77
//        height: 10
//        text: qsTr("Paramter2")
//        font.pointSize: 13
//    }

//    Label {
//        id: label4
//        x: 19
//        y: 344
//        text: qsTr("Paramter3")
//        font.pointSize: 13
//    }

//    TextField {
//        id: textField1
//        x: 102
//        y: 274
//        text: "Text Field"
//        horizontalAlignment: Text.AlignHCenter
//        renderType: Text.NativeRendering
//    }

//    TextField {
//        id: textField2
//        x: 102
//        y: 332
//        text: "Text Field"
//        horizontalAlignment: Text.AlignHCenter
//        renderType: Text.NativeRendering
//    }

//    Label {
//        id: label6
//        x: 12
//        y: 430
//        width: 55
//        height: 31
//        text: qsTr("Status: 1.0")
//        font.pointSize: 12
//    }

//    Label {
//        id: label7
//        x: 12
//        y: 476
//        width: 55
//        height: 31
//        text: qsTr("Status: 2.0")
//        font.pointSize: 12
//    }

//    Label {
//        id: label8
//        x: 12
//        y: 522
//        width: 55
//        height: 31
//        text: qsTr("Status: 3.0")
//        font.pointSize: 12
//    }

//    Label {
//        id: label9
//        x: 12
//        y: 568
//        width: 55
//        height: 39
//        text: qsTr("Status: 4.0")
//        font.pointSize: 12
//    }
//    Button {
//        id: tabButton
//        x: 222
//        y: 596
//        width: 48
//        height: 40

//        text: qsTr("OK")
//        onReleased: {
//            var num = 1
//            var repeat = false
//            while (num < menu.count) {
//                if (menu.actionAt(num).text == input1.text
//                        || input1.text == "") {
//                    repeat = true
//                }
//                num++
//            }
//            if (!repeat) {
//                var newObject = Qt.createQmlObject(
//                            "import QtQuick.Controls 2.3;Action{  checkable:
//true;checked: true}", parent, "dynamicSnippet")
//                newObject.text = input1.text
//                menu.addAction(newObject)
//            }
//        }
//    }

//    Button {
//        id: tabButton1
//        x: 276
//        y: 596
//        width: 50
//        height: 40
//        text: qsTr("Exit")
//        onClicked: {

//            myFile.close()
//            var newObject = Qt.createQmlObject(
//                        "import QtQuick.Controls 2.3;import FileIO2 1.0;FileIO2 {
//id: myFile2
//source: \"/root/good.txt\"
//onError: console.log(msg)
//}", parent, "dynamicSnippet")
//            var num = 0

//            var name = menu.actionAt(num).text
//            while (name != null) {
//                console.log(name)
//                newObject.write(name)
//                newObject.write("\n")
//                num++
//                if (menu.actionAt(num) == null) {
//                    break;
//                }
//                name = menu.actionAt(num).text
//            }
//            console.log("Finished!!")
//            Qt.quit();
//        }
//    }

//    Tumbler {
//        id: tumbler
//        x: 82
//        y: 661
//        model: 10
//    }

//    Tumbler {
//        id: tumbler1
//        x: 162
//        y: 661
//        model: 10
//    }
Pane
{
    id:p
    width: 288
    height: 100

    focus: true
     Keys.enabled: true;
     font.family: "@宋体"
     font.pixelSize: size
     Text {
          text: "Hello World!"
          color: "lightsteelblue"
          width: parent.width
          wrapMode: Text.WordWrap
          font.family: "@宋体"
          font.pixelSize: size
      }
    Tumbler {
        id: tumbler1
        x: -12
        y: -12
        width: 44
        height: 100
        model: [""]
        Keys.enabled: true;
         focus: true

        Keys.onPressed:{

        console.log("Press!1")
            if(event.key == Qt.Key_Right)
            {
            tumbler1.focus = false;
            tumbler.focus = true}

            if(event.key == Qt.Key_Up)
            {
                tumbler1.currentIndex-=1;
            }
            if(event.key == Qt.Key_Down){
                tumbler1.currentIndex+=1;
  }

        }
        MouseArea{
            id:m1
            anchors.fill:parent
            onClicked: {
           tumbler.focus = false;
           tumbler1.focus = true;
           m1.enabled = false;
           m.enabled = true;
       }}

    }
    Tumbler {
        id: tumbler
        x: 32
        y: -8
        width: 44
        height: 96
        model: 100
        Keys.enabled: true;
         focus: true
        Keys.onPressed:{

        console.log("Press!1")
            if(event.key == Qt.Key_Left)
            {
            tumbler.focus = false;
            tumbler1.focus = true}
          if(event.key == Qt.Key_Up)
          {
              tumbler.currentIndex-=1;
          }
          if(event.key == Qt.Key_Down){
              tumbler.currentIndex+=1;
}
        }
        MouseArea{
            id:m
            anchors.fill:parent
            onClicked: {
           tumbler1.focus = false;
           tumbler.focus = true;
                m.enabled = false;
                m1.enabled = true;
            }}

    }

    SpinBox {
        id: spinBox
        x: 84
        y: 16
    }

    }




