import string

def getInfo(fileObj):
    newDict = {}
    readFile = fileObj.read().split('\n')
    for char in readFile[0][:-3]:
        if not char.isnumeric():
            print('Invalid characters in instruction line. Expected number of lines got: %c.' %(char), end=' ')
            return False
    newDict['validChars'] = readFile[0][-3:-1]
    newDict['full'] = readFile[0][-1]
    newDict['obs'] = readFile[0][-2]
    newDict['empty'] = readFile[0][-3]
    newDict['lines'] = int(readFile[0][:-3])
    newDict['map'] = readFile[1:]
    if newDict['map'][-1] == '':
        del(newDict['map'][-1])
    return newDict

def validateInfo(mapInfo):
    if (len(mapInfo['map']) != mapInfo['lines']):
        print('Number of lines in map is not equal to number of lines in instruction. ', end=' ')
        return False
        
    
    for i in range(len(mapInfo['map'])):
        if not any(j in mapInfo['validChars'] for j in mapInfo['map'][i]):
            print('Characters in map not equal to characters in information line. ', end='')
            return False
        elif i < mapInfo['lines'] - 1 and len(mapInfo['map'][i]) != len(mapInfo['map'][i + 1]):
            print('Lines in map not the same lenght. ', end='')
            return False
            
    return True

def minSqr(newMatrix, col, i, j):
    
    a = col[j - 1]
    b = newMatrix[i - 1][j]
    c = newMatrix[i - 1][j - 1]
    if a and b and c == 0:
        return 1
    else:
        d = a
        if d > b:
            d = b
        if d > c:
            d = c
    return d + 1
    

def getSolvedMapInfor(mapInfo):

    newMatrix = []
    solvedMapInfor = {
        'min_i'     : 0,
        'min_j'     : 0,
        'max_i'     : 0,
        'max_j'     : 0,
        'max_sqr'   : 0
    }
    for i in range(mapInfo['lines']):
        col = []
        for j in range(len(mapInfo['map'][i])):
            if mapInfo['map'][i][j] == mapInfo['empty']:
                if i and j != 0:
                    col.append(minSqr(newMatrix, col, i, j))
                else:
                    col.append(1)
            elif mapInfo['map'][i][j] == mapInfo['obs']:
                col.append(0)
            if col[j] > solvedMapInfor['max_sqr']:
                solvedMapInfor['max_sqr'] = col[j]
                solvedMapInfor['max_i'] = i
                solvedMapInfor['max_j'] = j
                solvedMapInfor['min_i'] = (i + 1) - col[j]
                solvedMapInfor['min_j'] = (j + 1) - col[j]
        newMatrix.append(col)
    return (solvedMapInfor)

def printSolved(mapInfo, solved):
    for i in range(mapInfo['lines']):
        for j in range(len(mapInfo['map'][i])):
            if i >= solved['min_i'] and i <= solved['max_i'] and j >= solved['min_j'] and j <= solved['max_j']:
                print(mapInfo['full'], end='')
            else:
                print(mapInfo['map'][i][j], end='')
        print()
    print()
                
def solveMap(fileObj):
    mapInfo = getInfo(fileObj)
    if not mapInfo or not validateInfo(mapInfo):
        print('%s is an invalid map.' %(fileObj.name))
        return
    solvedMapInfor = getSolvedMapInfor(mapInfo)
    print('The biggest square for map %s is %i, located at %i, %i coordinates: ' %(fileObj.name, solvedMapInfor['max_sqr'], solvedMapInfor['min_i'], solvedMapInfor['min_j']))
    printSolved(mapInfo, solvedMapInfor) 
