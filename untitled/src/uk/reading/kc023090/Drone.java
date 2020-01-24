package uk.reading.kc023090;

import java.util.ArrayList;
import java.util.List;

import javafx.animation.AnimationTimer;
import javafx.application.Application;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
public class Drone extends Application{

    Pane root = new Pane();
    List droneCount = new ArrayList();
    List weakDroneCount = new ArrayList();
    List predatorDroneCount = new ArrayList();
    List minIndex = new ArrayList();
    AnimationTimer timer;

    public static void main(String[] args) {
        launch();
    }

    @Override
    public void start(final Stage primaryStage) throws Exception {

        //adding Drone at the begining of the session
        for (int i = 0; i < 100; i++) {
            minIndex.add(0);
            droneCount.add(food());
            root.getChildren().add((Node) droneCount.get(i));
        }



        //adding first drone
        weakDroneCount.add(weakDrone(randNum(0, 1000), randNum(0, 800)));
        root.getChildren().add((Node) weakDroneCount.get(0));

        //starting animation and all stuff
        timer = new AnimationTimer() {

            @Override
            public void handle(long arg0) {
                gameUpdate();
                primaryStage.setTitle("Drone set: " + weakDroneCount.size());
            }

        };
        timer.start();

        //Image img = new Image("https://as2.ftcdn.net/jpg/01/72/89/83/500_F_172898323_SLtrhEhmmKXbprbomUua1dqSdlczJivb.jpg");


        Scene scene = new Scene(root, 1000, 800);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Drones: 1");
        primaryStage.show();

    }

    public Circle food() {
        Circle circle = new Circle();
        circle.setLayoutX(randNum(0, 1000));
        circle.setLayoutY(randNum(0, 800));
        circle.setRadius(2);
        circle.setFill(Color.rgb(randNum(0, 256), randNum(0, 256), randNum(0, 256)));
        return circle;
    }
    public Circle weakDrone(double d, double e) {
        Circle c = new Circle();
        c.setLayoutX(d);
        c.setLayoutY(e);
        c.setRadius(5);
        c.setFill(Color.DARKGREEN);
        return c;
    }



    /**
     *
     */
    public void gameUpdate() {




        for(int i = 0; i < weakDroneCount.size(); i ++) {

            int[] index = new int[weakDroneCount.size()];


            //checking if ready to divide
            if(((Circle)weakDroneCount.get(i)).getRadius() >= 10){
                ((Circle)weakDroneCount.get(i)).setRadius(5);
                weakDroneCount.add(weakDrone(((Circle)weakDroneCount.get(i)).getLayoutX() + 10, ((Circle)weakDroneCount.get(i)).getLayoutY() + 10));
                root.getChildren().add((Node) ((List)weakDroneCount).get(weakDroneCount.size() - 1));
            }
            //starving and dying code
            ((Circle)weakDroneCount.get(i)).setRadius(((Circle)weakDroneCount.get(i)).getRadius() - 0.005);
            if(((Circle)weakDroneCount.get(i)).getRadius() <= 2){
                root.getChildren().remove(((Circle)weakDroneCount.get(i)));
                weakDroneCount.remove(((Circle)weakDroneCount.get(i)));

            }

            double minDistance = Math.sqrt(Math.pow((((Circle)weakDroneCount.get(0)).getLayoutX() - ((Circle) droneCount.get(0)).getLayoutX()), 2) + Math.pow((((Circle)weakDroneCount.get(0)).getLayoutY() - ((Circle) droneCount.get(0)).getLayoutY()), 2));


            for(int j = 0; j <  droneCount.size(); j++) {

                //closest Distance calculation

                if (minDistance > Math.sqrt(Math.pow((((Circle)weakDroneCount.get(i)).getLayoutX() - ((Circle) droneCount.get(j)).getLayoutX()), 2) + Math.pow((((Circle)weakDroneCount.get(i)).getLayoutY() - ((Circle) droneCount.get(j)).getLayoutY()), 2))){
                    minDistance = Math.min(minDistance, Math.sqrt(Math.pow((((Circle)weakDroneCount.get(i)).getLayoutX() - ((Circle) droneCount.get(j)).getLayoutX()), 2) + Math.pow((((Circle)weakDroneCount.get(i)).getLayoutY() - ((Circle) droneCount.get(j)).getLayoutY()), 2)));
                    index[i] = j;
                }


                //eating
                if(((((Circle)weakDroneCount.get(i)).getLayoutX() > ((Circle) droneCount.get(j)).getLayoutX() - ((Circle)weakDroneCount.get(i)).getRadius())
                        &&  (((Circle)weakDroneCount.get(i)).getLayoutX() < ((Circle) droneCount.get(j)).getLayoutX() + ((Circle)weakDroneCount.get(i)).getRadius()))
                        && ((((Circle)weakDroneCount.get(i)).getLayoutY() > ((Circle) droneCount.get(j)).getLayoutY() - ((Circle)weakDroneCount.get(i)).getRadius())
                        &&  (((Circle)weakDroneCount.get(i)).getLayoutY() < ((Circle) droneCount.get(j)).getLayoutY() + ((Circle)weakDroneCount.get(i)).getRadius()))) {
                    //code of eating and removing food
                    root.getChildren().remove( droneCount.get(j));
                     droneCount.remove(j);
                     droneCount.add(food());
                    root.getChildren().add((Node)  droneCount.get( droneCount.size() - 1));

                    ((Circle) weakDroneCount.get(i)).setRadius(((Circle)weakDroneCount.get(i)).getRadius() + 1);
                }
            }

            //path for finding food and moving

            if(((Node)weakDroneCount.get(i)).getLayoutX() > ((Node) droneCount.get(index[i])).getLayoutX()) {
                if(movable(((Circle)weakDroneCount.get(i)).getLayoutX(), ((Circle)weakDroneCount.get(i)).getLayoutY(), i)) {
                    ((Node) weakDroneCount.get(i)).setLayoutX(((Node) weakDroneCount.get(i)).getLayoutX() - 1);
                }
                else {
                    ((Node) weakDroneCount.get(i)).setLayoutX(((Node) weakDroneCount.get(i)).getLayoutX() + 1);
                }
            }

            if(((Node)weakDroneCount.get(i)).getLayoutX() < ((Node) droneCount.get(index[i])).getLayoutX()) {
                if(movable(((Circle)weakDroneCount.get(i)).getLayoutX(), ((Circle)weakDroneCount.get(i)).getLayoutY(), i)) {
                    ((Node) weakDroneCount.get(i)).setLayoutX(((Node) weakDroneCount.get(i)).getLayoutX() + 1);
                }
                else {
                    ((Node) weakDroneCount.get(i)).setLayoutX(((Node) weakDroneCount.get(i)).getLayoutX() - 1);
                }
            }

            if(((Node)weakDroneCount.get(i)).getLayoutY() > ((Node) droneCount.get(index[i])).getLayoutY()) {
                if(movable(((Circle)weakDroneCount.get(i)).getLayoutX(), ((Circle)weakDroneCount.get(i)).getLayoutY(), i)) {
                    ((Node) weakDroneCount.get(i)).setLayoutY(((Node) weakDroneCount.get(i)).getLayoutY() - 1);
                }
                else {
                    ((Node) weakDroneCount.get(i)).setLayoutX(((Node) weakDroneCount.get(i)).getLayoutX() + 1);
                }
            }

            if(((Node)weakDroneCount.get(i)).getLayoutY() < ((Node) droneCount.get(index[i])).getLayoutY()) {
                if(movable(((Circle)weakDroneCount.get(i)).getLayoutX(), ((Circle)weakDroneCount.get(i)).getLayoutY(), i)) {
                    ((Node) weakDroneCount.get(i)).setLayoutY(((Node) weakDroneCount.get(i)).getLayoutY() + 1);
                }
                else {
                    ((Node) weakDroneCount.get(i)).setLayoutX(((Node) weakDroneCount.get(i)).getLayoutX() - 1);
                }
            }



        }


    }

    public int randNum(int min, int max) {
        return (int)(Math.random() * max + min);
    }

    //checking if other bacteria ocupied that place already
    public boolean movable(double x, double y, int ind){
        for(int i = 0; i < weakDroneCount.size(); i++) {
            if(ind == i) {
                break;
            }
            else if(((((Circle)weakDroneCount.get(i)).getLayoutX() > x - ((Circle)weakDroneCount.get(i)).getRadius())
                    &&  (((Circle)weakDroneCount.get(i)).getLayoutX() < x + ((Circle)weakDroneCount.get(i)).getRadius()))
                    && ((((Circle)weakDroneCount.get(i)).getLayoutY() > y - ((Circle)weakDroneCount.get(i)).getRadius())
                    &&  (((Circle)weakDroneCount.get(i)).getLayoutY() < y + ((Circle)weakDroneCount.get(i)).getRadius()))) {
                return false;
            }

        }
        return true;
    }

}