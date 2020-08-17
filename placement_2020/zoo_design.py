cost_h, cost_c, cost_a = map(int, input().split())
max_area_h, max_area_c, max_area_a = map(int, input().split())

min_no_h, min_area_h = map(int, input().split())
min_no_c, min_area_c = map(int, input().split())
min_no_a, min_area_a = map(int, input().split())

total_area = int(input())
left_area = 0

cost_sum = sum([cost_h,cost_c,cost_a])
#choose max cost animal  --> provide min area
temp = max(cost_h, cost_c, cost_a)
cost_sum -= temp
if temp == cost_h:
 cost = min_no_h * min_area_h * cost_h
 left_area += min_area_h * min_no_h
elif temp == cost_c:
 cost = min_no_c * min_area_c * cost_c
 left_area += min_area_c * min_no_c
else:
 cost = min_no_a * min_area_a * cost_a
 left_area += min_area_a * min_no_a


#chosse min cost animal --> provide mx area
temp = min(cost_h,cost_c,cost_a)
if total_area - left_area >= 
cost_sum -= temp
if temp == cost_h:
	cost += max_area_h * cost_h
	left_area += max_area_h
elif temp == cost_c:
	cost += max_area_c * cost_c
	left_area += max_area_c
else:
	cost += max_area_a * cost_a
	left_area += max_area_a
#cal rest area
print(cost+(total_area-left_area)*cost_sum)

