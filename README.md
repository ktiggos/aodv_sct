### Prerequisites
```
sudo apt-get update
sudo apt-get install -y build-essentials
sudo apt-get install -y nlohmann-json3-dev
```

### Build Project
Inside repo folder, run:
```
cmake -S . -B build
cmake --build build/
```

### Run demo AODV supervisor sim
After building the project run:
```
./build/demo_aodv_sc
```
The exe `demo_aodv_sc` reads the json file `data/event_seq.json` which defines a specific event sequence (word) for the AODV system supervisors. The program will simulate transitions and produce the output file `out/state_trace.json`, which includes all of the node supervisor state snapshots at each iteration.

To define a new event sequence simply edit `event_seq.json`, or you can add a new json file and edit the hard-coded path of `src/demo_aodv_sc.cpp`.
