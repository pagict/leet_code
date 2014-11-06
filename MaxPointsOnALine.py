# Definition for a point
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        x_way_set=[]
        y_way_set=[]
        for p in points:
            x_insert_flag = False
            y_insert_flag = False
            for tmpList in x_way_set:
                if tmpList[0].x == p.x:
                    tmpList.append(p)
                    x_insert_flag = True
                    break;
            if x_insert_flag is False:
                x_way_set.append([p])
                
            for tmpList in y_way_set:
                if tmpList[0].y == p.y:
                    tmpList.append(p)
                    y_insert_flag = True
                    break;
            if y_insert_flag is False:
                y_way_set.append([p])
        
        max = 0
        for l in x_way_set:
            if len(l)>max:
                max = len(l)
        for l in y_way_set:
            if len(l)>max:
                max = len(l)
        
        return max
        