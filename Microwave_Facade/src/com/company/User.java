package com.company;


// ����c �����������, ���� ������� �������������
public class User {
    public static void main(String[] args) {
        HeatingElement heatingElement = new HeatingElement();
        GuideRoller guideRoller = new GuideRoller();
        ControlPanel controlPanel = new ControlPanel();

            Microwave microwave = new Microwave(heatingElement, guideRoller, controlPanel);
            microwave.startMicrowave();
    }
}
