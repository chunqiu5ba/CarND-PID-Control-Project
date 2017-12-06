# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## PID Controller

* P: Proportional parameter computes an output proportinal to the set point(lane center), also called cross-track-error(cte). The vehcial will oscillates around the setpoint under P controller only.

* D: differential parameter computes the derivative of the cte over time period,it will smooth the oscillation effect caused by P  

* I: Integral parameter calculates the sum of the cte over time, and remove thisbias will help the set poiont could be reached. The source of this error could come from different sysmatic bias like steering drift.

## Hyperparameter Tuning

Steering PID paramenters are finalized at: P-0.05, I-0.007, D-2, after manually tuning. I stastarted with testing P first and leave I and D at zero, then increase D to keep the vechcle on the track, then adjusting I to keep the car more closer to the center lane. 

Although suggeest by the project that the second PID controller could be implemeneted over the throttle, I didn't feel it helped alot. Throttle was set as a negtive correlation of the abosulte vaule of cte: the far way from center, the lower throttle, even brackes.

## Thing to improve

The vehicle can drive along the track at about 15 mph with my implementation, but the speed is not satisfied. Also the vehicle oscilation is still large. 

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

