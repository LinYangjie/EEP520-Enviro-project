EEP520-Enviro-project: Protect UW STATUE 
===
Procedures
===

First, you will need to download my files, do
```bash
git clone https://github.com/LinYangjie/EEP520-Enviro-project.git
```

Then, start the docker image environment, do
```bash
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.6 bash
esm start

```
This will start a bash prompt from which you can work my project and run the enviro server.
The command `esm start` uses the <u>e</u>nviro <u>s</u>etup <u>m</u>anager to start a web server from which your browser can access the ENVRIO client. 

Project Goal
===
The project goal is to guard the UW Statue prevent it from attacking by other agents. 

Game Description and Instruction
===
