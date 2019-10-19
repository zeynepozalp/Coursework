def name(tree):
    return tree[0]
def force(tree):
    return tree[1]
def children(tree):
    return tree[2:]
def is_leaf(tree):
    return True if len(tree) == 2 else False

def help_ben_solo(tree,t):
    global tree_list, l, traverse_output,traverse_output2
    l=len(tree)

    def max_depth(tree):
        if is_leaf(tree):
            return 1
        else:
            return max(max_depth_forest(children(tree))) + 1

    def max_depth_forest(forest):
        if len(forest) == 0:
            return []
        else:
            return [max_depth(forest[0])] + max_depth_forest(forest[1:])

    height = max_depth(tree)

    traverse_output = []

    def height_insert(tree, h=height):
        if is_leaf(tree):
            tree.append(h)
            tree.append(0)
        else:
            tree.insert(2, h)
            tree.insert(3, 1)
            for i in tree[4:]:
                height_insert(i, h - 1)
        return tree

    def traverse(tree):
        if len(tree) == 4:
            traverse_output.append(tree)
        else:
            traverse_output.append(tree[:4])
            for x in tree[4:]:
                traverse(x)
            return traverse_output

    def r_traverse(lst):
        i = 0
        while i < len(lst):
            if lst[i][3] == 0 and lst[i][2]<lst[i-1][2]:
                lst[i - 1].append(lst[i])
                del lst[i]
            else:
                i += 1
        return r_traverse_helper(lst)

    def r_traverse_helper(lst):
        new = lst[::-1]
        i = 0
        while i < len(new):
            if len(new) == 1:
                break
            elif i == len(new) - 1:
                i = 0
            elif new[i][2] == new[i + 1][2]:
                i += 1
            elif new[i][2] < new[i + 1][2]:
                new[i + 1].append(new[i])
                del new[i]
                i=0
            else:
                i += 1
        return new

    def cons_1(lst):
        for i in lst:
            for j in lst:
                if i==j:
                    continue
                elif i[1]>j[1] and i[2]<j[2]:
                    i[0],j[0]=j[0],i[0]
                    i[1], j[1] = j[1], i[1]
                elif j[1]>i[1] and j[2]<i[2]:
                    i[0], j[0] = j[0], i[0]
                    i[1], j[1] = j[1], i[1]
        return lst

    def find_path(lst, item):
        index = lst.index(item)
        new_lst = lst[index::-1]
        path = []
        h = item[2]
        for i in new_lst:
            if i[2] == h + 1:
                path.append(i)
                h += 1
        return path

    def sum_force(tree):
        if len(tree) == 4:
            sum=0
        else:
            sum = 0
            for item in tree[4:]:
                sum += force(item)
        return sum

    def sum_insert(tree):
        if len(tree) == 4:
            tree.append(sum_force(tree))
        else:
            tree.insert(4, sum_force(tree))
            for i in tree[5:]:
                sum_insert(i)
        return tree

    traverse_output2 = []

    def traverse2(tree):
        if len(tree) == 5:
            traverse_output2.append(tree)
        else:
            traverse_output2.append(tree[:5])
            for x in tree[5:]:
                traverse2(x)
            return traverse_output2


    def cons_2(lst, t):
        def find_max_force(lst, h):
            max_force = 0
            for x in lst:
                if x[2] < h and x[1] > max_force:
                    max_force = x[1]
            return max_force
        l = len(lst)
        output = [lst]
        i=0
        while i<l:
            k = len(lst) - i - 1
            if output[0][k][2] < t:
                path = find_path(lst, lst[k])
                for j in range(len(path) - 1):
                    max=find_max_force(output[0],path[j][2])
                    if (output[0][k][1] + path[j + 1][-1] < path[j + 1][1] or output[0][k][1] + path[j + 1][-1] == path[j + 1][1]) and output[0][k][1]>=max:
                        old_h=output[0][k][2]
                        output[0][k][2] = path[j + 1][2] - 1
                        path[j + 1][-1] += output[0][k][1]
                        if old_h + 1 < path[j + 1][2] - 1:
                            ind=output[0].index(path[j + 1])
                            item=output[0][k]
                            output[0].remove(item)
                            output[0].insert(ind+1,item)
                            i-=1
                        break
                else:
                    max = find_max_force(output[0], path[-1][2])
                    if output[0][k][1] + path[-1][-1] < path[-1][1]and output[0][k][1]>=max:
                        output[0][k][2] = path[-1][2] - 1
                        path[-1][-1] += output[0][k][1]
            i+=1
        return output[0]

    def find_retired(lst,t):
        retired=[]
        for item in lst:
            if item[2]<t:
                retired.append(item)
        return retired
    def remover_retired(lst,t):
        output=[]
        for item in lst:
            if item[2]>=t:
                output.append(item)
        return output

    def r_insert(tree):
        new_tree = []
        if len(tree) == 5 and type(tree[-1]) == int:
            new_tree = [tree[0], tree[1]]
        else:
            new_tree = [tree[0], tree[1]]
            for i in tree[5:]:
                new_tree.append(r_insert(i))
        return new_tree
    def r_insert2(lst):
        new_lst=[]
        for i in lst:
            new_lst.append(i[0])
        return new_lst
    tree_0=height_insert(tree)
    tree_1=traverse(tree_0)
    tree_2=cons_1(tree_1)
    tree_3=r_traverse(tree_2)[0]
    tree_4=sum_insert(tree_3)
    tree_5=traverse2(tree_4)
    tree_6=cons_2(tree_5,t)
    retired=find_retired(tree_6,t)
    tree_7=remover_retired(tree_6,t)
    tree_8=r_traverse(tree_7)[0]
    retired_final=r_insert2(retired)
    final=r_insert(tree_8)
    return (final,retired_final)
