package designpatterns.command;

//Concrete Command
public class LightOffCommand implements Command {

    Light light;

    public LightOffCommand(Light light) {
        this.light = light;
    }

    public void execute() {
        light.switchOff();
        System.out.println("Desliguei a luz");
    }
}
