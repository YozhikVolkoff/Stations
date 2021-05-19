# Stations
Railroad system with a simple interface
You may start an "Interface.py" and go on with commands: 'new pl' (platform), 'new st' (station), 'new tr' (train), 'new rw' (railway), 'go' and 'q'
To be created, platforms and stations need only a name; railways need two names (of stations or platforms) and two numbers: passengers max load and cargo max load.
Trains need type (boolean, true = passenger train, false = cargo train; cargo trains are allowed to move only between stations), capacity
and two names of stations/platforms (from/to).
Command 'go' will find a route for each train (or define that there is no possible route for this one) and then print output.
Command 'q' is for quitting.
