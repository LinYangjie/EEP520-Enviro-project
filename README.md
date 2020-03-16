EEP520-Enviro-project: Protect UW Statue 
===

Project Goal
===

The project goal is to guard the UW Statue prevent it from attacking by other agents. 
I label it with some sacrastic text on what I encounter this quarter.

Game Description and Instructions
===

The agent you will control is a "pink" one. Click the button "Start" at the right top of the webpage when you ready.
Press `1` to select "Bullet", Press `2` to select "Missile". Using `A`,`S`,`W`,`D` to control agent and `space` to fire. 
>
- `Bullet` is a normal weapon, and `Missile` will explode after a little time, which can't do damage to the target before the explosion.
- if your agent bump into those targets you will return to the place where you start.

Agents introduction
===
- ***player :*** the agent you will be controlling to shoot down other agents.
- ***virus :*** a circle-like agent with lowest hp which is moving toward statue.  
- ***assignemt :*** a boat-like agent with medium hp which is moving toward statue. 
- ***final project :*** the biggest and slowest circle-like agent with highest hp which is moving toward statue.
- ***who :*** the agent with sensor trigger event.
- ***government :*** the agent will guard once the event been triggered.
- ***statue :*** the agent you should protect.

Procedures
===

First, you will need to download my files, do
```bash
git clone https://github.com/LinYangjie/EEP520-Enviro-project.git
```

Then, start the docker image environment, do
```bash
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.5 bash
esm start

```
This will start a bash prompt from which you can run my project and the enviro server.
The command `esm start` uses the enviro setup manager to start a web server from which your browser can access the ENVRIO client.

Last, do
```bash
enviro
```
Then navigate to `http://localhost`, you should see the project works. 

You can press Ctrl-C to stop the enviro server.

Key Challenges
===
There are not too many challenges in my project. Most of it is depends on how I deal with it, the project is similar to Professor Kalvins' `examples/virus` file.(see https://github.com/klavinslab/enviro/tree/master/examples/virus)
>
But there are two points I have to deal with
- ***Missile Explosion :*** I use the function "add_agent" after amount of time when missile was lanuched, once it explode, the fragments wil go randomly and when it hit on the target, it will reduce the hp of the target.  
- ***Button click :*** In order to let user having time before the game start. I add a boolean variable to determine if player and other agents can move. Once the button been clicked, the game will start to run.


