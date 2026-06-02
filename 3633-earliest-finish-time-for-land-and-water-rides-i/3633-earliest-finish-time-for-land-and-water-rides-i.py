class Solution(object):
    def earliestFinishTime(self, landStartTime, landDuration,
                           waterStartTime, waterDuration):
        answer = float('inf')
        for i in range(len(landStartTime)):
            for j in range(len(waterStartTime)):
                land_finish = landStartTime[i] + landDuration[i]
                water_finish = waterStartTime[j] + waterDuration[j]
                finish1 = max(land_finish, waterStartTime[j]) + waterDuration[j]
                finish2 = max(water_finish, landStartTime[i]) + landDuration[i]
                answer = min(answer, finish1, finish2)
        return answer