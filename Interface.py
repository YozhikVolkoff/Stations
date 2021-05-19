import ctypes

lib_stations = ctypes.CDLL('./LTrain.so')

lib_stations.create_system.restype = ctypes.c_void_p
lib_stations.create_station.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
lib_stations.create_station.restype = ctypes.c_void_p
lib_stations.create_platform.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
lib_stations.create_platform.restype = ctypes.c_void_p
lib_stations.create_railway.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_char_p, ctypes.c_int, ctypes.c_int]
lib_stations.create_railway.restype = ctypes.c_void_p
lib_stations.create_train.argtypes = [ctypes.c_void_p, ctypes.c_bool, ctypes.c_int, ctypes.c_char_p, ctypes.c_char_p]
lib_stations.create_train.restype = ctypes.c_void_p
lib_stations.trains_go.argtypes = [ctypes.c_void_p]
lib_stations.dispose_system.argtypes = [ctypes.c_void_p]

S = lib_stations.create_system()

while True:
    c = str(input())
    if c == "new rw":
        rw = str(input("Enter parameters\n"))
        rw_list = rw.split()
        try:
            name1 = ctypes.c_char_p(rw_list[0].encode('utf-8'))
            try:
                name2 = ctypes.c_char_p(rw_list[1].encode('utf-8'))
                try:
                    pass_cap = int(rw_list[2])
                    try:
                        cargo_cap = int(rw_list[3])
                        a = lib_stations.create_railway(S, name1, name2, pass_cap, cargo_cap)
                        if a:
                            print("Successfully")
                        else:
                            print("No such stations or platforms")
                    except:
                        print("Invalid cargo load")
                except:
                    print("Invalid pass. load")
            except:
                print("Invalid name of station/platform")
        except:
            print("Invalid name of station/platform")
    elif c == "new tr":
        tr = str(input("Enter parameters\n"))
        tr_list = tr.split()
        try:
            is_pass_str = tr_list[0]
            if is_pass_str == "cargo":
                is_pass = False
            elif is_pass_str == "pass":
                is_pass = True
            try:
                cap = int(tr_list[1])
                try:
                    name1 = ctypes.c_char_p(tr_list[2].encode('utf-8'))
                    try:
                        name2 = ctypes.c_char_p(tr_list[3].encode('utf-8'))
                        a = lib_stations.create_train(S, is_pass, cap, name1, name2)
                        if a:
                            print("Successfully")
                        else:
                            print("No such stations or platforms")
                    except:
                        print("Invalid name of station/platform")
                except:
                    print("Invalid name of station/platform")
            except:
                print("Invalid capacity")
        except:
            print("Invalid type")
    elif c == "new pl":
        pl = str(input("Enter parameter\n"))
        pl_list = pl.split()
        try:
            name = ctypes.c_char_p(pl_list[0].encode('utf-8'))
            a = lib_stations.create_platform(S, name)
            if a:
                print("Successfully")
            else:
                print("Error while creating platform")
        except:
            print("Invalid name of platform")
    elif c == "new st":
        st = str(input("Enter parameter\n"))
        st_list = st.split()
        try:
            name = ctypes.c_char_p(st_list[0].encode('utf-8'))
            a = lib_stations.create_station(S, name)
            if a:
                print("Successfully")
            else:
                print("Error while creating station")
        except:
            print("Invalid name of station")
    elif c == "go":
        lib_stations.trains_go(S)
    elif c == "q":
        break
    else:
        print("Invalid command")

lib_stations.dispose_system(S)
#Dsl, ply
