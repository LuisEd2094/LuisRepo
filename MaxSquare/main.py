import sys, os, solvemap

def main():
    if (len(sys.argv) < 2):
        exit("Not enough arguments. Please provide with a .txt file with a map.")
    for i in range(1 , len(sys.argv)):
        if os.path.isfile(sys.argv[i]):
            if os.path.splitext(sys.argv[i])[1].lower() == '.txt':
                try:
                    fileObj = open(sys.argv[i])
                except OSError:
                    print("could not open file: %s" %(sys.argv[i]))
                solvemap.solveMap(fileObj)
                fileObj.close()
            else:
                print("File : %s is not a valid .txt file." %(sys.argv[i]))
                
        else:
            print("Parameter %s is not a file path, please provide with a valid .txt file path." %(sys.argv[i]))
        
if __name__ == '__main__':
    main()