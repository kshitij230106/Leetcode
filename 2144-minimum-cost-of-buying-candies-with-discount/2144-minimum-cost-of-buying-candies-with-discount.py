class Solution:
    def minimumCost(self, cost):
        cost.sort(reverse=True)

        totalCost = 0

        for i in range(0, len(cost), 3):
            totalCost += cost[i]

            if i + 1 < len(cost):
                totalCost += cost[i + 1]

        return totalCost