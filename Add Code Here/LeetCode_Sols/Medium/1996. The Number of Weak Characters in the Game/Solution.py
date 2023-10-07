class Solution(object):
    def numberOfWeakCharacters(self, properties):
        count = 0
        maxN = ~sys.maxint
        properties.sort(key=lambda x: (-x[0], x[1]))
        for i in range(len(properties)):
            if(properties[i][1] < maxN):
                count+=1
            maxN = max(maxN, properties[i][1])
        return count
