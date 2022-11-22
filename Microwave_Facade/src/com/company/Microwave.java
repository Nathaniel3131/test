package com.company;

public class Microwave {
    private final static long CONTROL_PANEL = 2;
    private final static long MICROWAVE_SECTOR = 2;
    private final static int HEATING_TIME = 3;

    private HeatingElement heatingElement;
    private GuideRoller guideRoller;
    private ControlPanel controlPanel;

    public Microwave(HeatingElement heatingElement, GuideRoller guideRoller, ControlPanel controlPanel) {
        this.heatingElement = heatingElement;
        this.guideRoller = guideRoller;
        this.controlPanel = controlPanel;
    }

    public void startMicrowave() {
        heatingElement.start();
        guideRoller.load(CONTROL_PANEL, ControlPanel.point(MICROWAVE_SECTOR, HEATING_TIME));
        heatingElement.setRotate(CONTROL_PANEL);
        heatingElement.heatingEnd();
    }
}
