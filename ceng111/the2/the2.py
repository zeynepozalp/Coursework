def minority_shape_intersect(shape_0,shape_1):
    global output_list, inside_point_100, inside_point_101, inside_point_110, inside_point_111, inside_point_120, inside_point_121, inside_point_102, inside_point_112, inside_point_122, edge_point_121, edge_point_120, edge_point_111, edge_point_110, edge_point_101, edge_point_100, edge_point_102, edge_point_112, edge_point_122

    def line_func((a, b), (c, d), (e, f), (g, h)):
        if a != c and e != g:
            m_0 = (b - d) / (a - c)
            n_0 = ((-m_0) * a) + b
            m_1 = (f - h) / (e - g)
            n_1 = ((-m_1) * e) + f
            if abs(m_0 - m_1) < 0.001 and abs(n_0 - n_1) < 0.001:
                sorted_x = sorted([a, c, e, g])
                x = sorted_x[1], m_0 * sorted_x[1] + ((-m_0) * a) + b
                y = sorted_x[2], m_0 * sorted_x[2] + ((-m_0) * a) + b
                return x
                return y
            elif abs(m_0 - m_1) > 0.001:
                intersect_x = (m_1 * e - m_0 * a + b - f) / (m_1 - m_0)
                intersect_y = m_0 * (intersect_x - a) + b
                sorted_x_0 = sorted([a, c])
                sorted_y_0 = sorted([b, d])
                sorted_x_1 = sorted([e, g])
                sorted_y_1 = sorted([f, h])
                c_0 = sorted_x_0[0] <= intersect_x <= sorted_x_0[1]
                c_1 = sorted_x_1[0] <= intersect_x <= sorted_x_1[1]
                c_2 = sorted_y_0[0] <= intersect_y <= sorted_y_0[1]
                c_3 = sorted_y_1[0] <= intersect_y <= sorted_y_1[1]
                if c_0 == c_1 == c_2 == c_3 == 1:
                    return intersect_x, intersect_y
                else:
                    return ()
            elif abs(m_0 - m_1) < 0.001 and abs(n_0 - n_1) > 0.001:
                return ()
            else:
                return ()
        elif a == c and e != g:
            m_1 = (f - h) / (e - g)
            point_0 = (a, m_1 * (a - e) + f)
            sorted_x_1 = sorted([e, g])
            sorted_y_1 = sorted([f, h])
            sorted_y_0 = sorted([b, d])
            if sorted_y_1[0] <= m_1 * (a - e) + f <= sorted_y_1[1] and sorted_x_1[0] <= a <= sorted_x_1[1] and \
                                    sorted_y_0[0] <= m_1 * (a - e) + f <= sorted_y_0[1]:
                return point_0
            else:
                return ()
        elif a != c and e == g:
            m_0 = (b - d) / (a - c)
            point_1 = (e, m_0 * (e - a) + b)
            sorted_x_0 = sorted([a, c])
            sorted_y_0 = sorted([b, d])
            sorted_y_1 = sorted([f, h])
            if sorted_y_0[0] <= m_0 * (e - a) + b <= sorted_y_0[1] and sorted_x_0[0] <= e <= sorted_x_0[1] and \
                                    sorted_y_1[0] <= m_0 * (e - a) + b <= sorted_y_1[1]:
                return point_1
            else:
                return ()
        else:
            return ()
    def is_point_inside((Px, Py), (Ax, Ay), (Bx, By), (Cx, Cy)):
        bx = Bx - Ax
        by = By - Ay
        cx = Cx - Ax
        cy = Cy - Ay
        x = Px - Ax
        y = Py - Ay
        d = bx * cy - cx * by
        wa = (x * (by - cy) + y * (cx - bx) + d) / d
        wb = (x * cy - y * cx) / d
        wc = (y * bx - x * by) / d
        if 0 <= wa <= 1 and 0 <= wb <= 1 and 0 <= wc <= 1:
            return Px, Py
        else:
            return ()
    def is_point_edge((a, b), (c, d), (e, f), (g, h)):
        if c!=e:
            m = (d-f) / (c-e)
            n = ((-m) * c) + d
            distance= abs(m*a-b+n)/((m*m+1)**0.5)
            if distance==0:
                return a,b
            else:
                return ()
        if e!=g:
            m = (f - h) / (e - g)
            n = ((-m) * e) + f
            distance = abs(m * a - b + n) / ((m * m + 1) ** 0.5)
            if distance == 0:
                return a, b
            else:
                return ()
        if g!=c:
            m = (h - d) / (g - c)
            n = ((-m) * g) + h
            distance = abs(m * a - b + n) / ((m * m + 1) ** 0.5)
            if distance == 0:
                return a, b
            else:
                return ()
        if c==a==e and (d<=b<=f or f<=b<=d):
            return a,b
        if e==a==g and (f<=b<=h or h<=b<=f):
            return a,b
        if g==a==c and (h<=b<=d or d<=b<=h):
            return a,b
        else:
            return ()
    def if_concave((a, b), (c, d), (e, f), (g, h)):
        if is_point_inside((a,b), (c, d), (e, f), (g,h))==():
            return False
        else:
            return True
    def remover(lst):
        if len(lst) == 1:
            return [lst[0]]
        else:
            for i in range(1, len(lst)):
                if abs(lst[0][0] - lst[i][0]) <= 0.001 and abs(lst[0][1] - lst[i][1]) <= 0.001:
                    lst = lst[1:]
            return [lst[0]] + remover(lst[1:])
    if len(shape_0)==len(shape_1)==3: #triangle-triangle
        x_000 = shape_0[0][0]
        y_000 = shape_0[0][1]
        x_001 = shape_0[1][0]
        y_001 = shape_0[1][1]
        x_002 = shape_0[2][0]
        y_002 = shape_0[2][1]
        x_010 = shape_1[0][0]
        y_010 = shape_1[0][1]
        x_011 = shape_1[1][0]
        y_011 = shape_1[1][1]
        x_012 = shape_1[2][0]
        y_012 = shape_1[2][1]
        int_point_00=line_func((x_000,y_000),(x_001,y_001),(x_010,y_010),(x_011,y_011))
        int_point_01=line_func((x_000,y_000),(x_001,y_001),(x_011,y_011),(x_012,y_012))
        int_point_02=line_func((x_000,y_000),(x_001,y_001),(x_012,y_012),(x_010,y_010))
        int_point_03=line_func((x_001,y_001),(x_002,y_002),(x_010,y_010),(x_011,y_011))
        int_point_04=line_func((x_001,y_001),(x_002,y_002),(x_011,y_011),(x_012,y_012))
        int_point_05=line_func((x_001,y_001),(x_002,y_002),(x_012,y_012),(x_010,y_010))
        int_point_06=line_func((x_002,y_002),(x_000,y_000),(x_010,y_010),(x_011,y_011))
        int_point_07=line_func((x_002,y_002),(x_000,y_000),(x_011,y_011),(x_012,y_012))
        int_point_08=line_func((x_002,y_002),(x_000,y_000),(x_012,y_012),(x_010,y_010))
        inside_point_00=is_point_inside((x_000,y_000),(x_010,y_010),(x_011,y_011),(x_012,y_012))
        inside_point_01=is_point_inside((x_001,y_001),(x_010,y_010),(x_011,y_011),(x_012,y_012))
        inside_point_02=is_point_inside((x_002,y_002),(x_010,y_010),(x_011,y_011),(x_012,y_012))
        inside_point_03=is_point_inside((x_010,y_010),(x_000,y_000),(x_001,y_001),(x_002,y_002))
        inside_point_04=is_point_inside((x_011,y_011),(x_000,y_000),(x_001,y_001),(x_002,y_002))
        inside_point_05=is_point_inside((x_012,y_012),(x_000,y_000),(x_001,y_001),(x_002,y_002))
        edge_point_00=is_point_edge((x_000,y_000),(x_010,y_010),(x_011,y_011),(x_012,y_012))
        edge_point_01=is_point_edge((x_001,y_001),(x_010,y_010),(x_011,y_011),(x_012,y_012))
        edge_point_02=is_point_edge((x_002,y_002),(x_010,y_010),(x_011,y_011),(x_012,y_012))
        edge_point_03=is_point_edge((x_010,y_010),(x_000,y_000),(x_001,y_001),(x_002,y_002))
        edge_point_04=is_point_edge((x_011,y_011),(x_000,y_000),(x_001,y_001),(x_002,y_002))
        edge_point_05=is_point_edge((x_012,y_012),(x_000,y_000),(x_001,y_001),(x_002,y_002))
        output_list=[int_point_00,int_point_01,int_point_02,int_point_03,int_point_04,int_point_05,int_point_06,int_point_07,int_point_08,
                     inside_point_00,inside_point_01,inside_point_02,inside_point_03,inside_point_04,inside_point_05,
                     edge_point_00,edge_point_01,edge_point_02,edge_point_03,edge_point_04,edge_point_05]
        a=output_list.count(())
        for i in range(0,a):
            b=output_list.index(())
            del output_list[b]
        output_list=list(set(output_list))
        if len(output_list)<3:
            return []
        else:
            output_list=remover(output_list)
            return output_list
    if len(shape_0) == 3 and len(shape_1) == 4:  # triangle-rectangle
        x_100 = shape_0[0][0]
        y_100 = shape_0[0][1]
        x_101 = shape_0[1][0]
        y_101 = shape_0[1][1]
        x_102 = shape_0[2][0]
        y_102 = shape_0[2][1]
        x_110 = shape_1[0][0]
        y_110 = shape_1[0][1]
        x_111 = shape_1[1][0]
        y_111 = shape_1[1][1]
        x_112 = shape_1[2][0]
        y_112 = shape_1[2][1]
        x_113 = shape_1[3][0]
        y_113 = shape_1[3][1]
        int_point_10 = line_func((x_100, y_100), (x_101, y_101), (x_110, y_110), (x_111, y_111))  # 01-01
        int_point_11 = line_func((x_100, y_100), (x_101, y_101), (x_111, y_111), (x_112, y_112))  # 01-12
        int_point_12 = line_func((x_100, y_100), (x_101, y_101), (x_112, y_112), (x_113, y_113))  # 01-23
        int_point_13 = line_func((x_101, y_101), (x_102, y_102), (x_110, y_110), (x_111, y_111))  # 12-01
        int_point_14 = line_func((x_101, y_101), (x_102, y_102), (x_111, y_111), (x_112, y_112))  # 12-12
        int_point_15 = line_func((x_101, y_101), (x_102, y_102), (x_112, y_112), (x_113, y_113))  # 12-23
        int_point_16 = line_func((x_102, y_102), (x_100, y_100), (x_110, y_110), (x_111, y_111))  # 20-01
        int_point_17 = line_func((x_102, y_102), (x_100, y_100), (x_111, y_111), (x_112, y_112))  # 20-12
        int_point_18 = line_func((x_102, y_102), (x_100, y_100), (x_112, y_112), (x_113, y_113))  # 20-23
        int_point_19 = line_func((x_100, y_100), (x_101, y_101), (x_113, y_113), (x_110, y_110))  # 01-30
        int_point_110 = line_func((x_101, y_101), (x_102, y_102), (x_113, y_113), (x_110, y_110))  # 12-30
        int_point_111 = line_func((x_102, y_102), (x_100, y_100), (x_113, y_113), (x_110, y_110))  # 20-30
        inside_point_13 = is_point_inside((x_110, y_110), (x_100, y_100), (x_101, y_101), (x_102, y_102))
        inside_point_14 = is_point_inside((x_111, y_111), (x_100, y_100), (x_101, y_101), (x_102, y_102))
        inside_point_15 = is_point_inside((x_112, y_112), (x_100, y_100), (x_101, y_101), (x_102, y_102))
        inside_point_16 = is_point_inside((x_113, y_113), (x_100, y_100), (x_101, y_101), (x_102, y_102))
        edge_point_13 = is_point_edge((x_110, y_110), (x_100, y_100), (x_101, y_101), (x_102, y_102))
        edge_point_14 = is_point_edge((x_111, y_111), (x_100, y_100), (x_101, y_101), (x_102, y_102))
        edge_point_15 = is_point_edge((x_112, y_112), (x_100, y_100), (x_101, y_101), (x_102, y_102))
        edge_point_16 = is_point_edge((x_113, y_113), (x_100, y_100), (x_101, y_101), (x_102, y_102))
        output_list = [int_point_10, int_point_11, int_point_12, int_point_13, int_point_14, int_point_15,int_point_16, int_point_17, int_point_18, int_point_19, int_point_110, int_point_111,
                           inside_point_13,inside_point_14, inside_point_15, inside_point_16,
                           edge_point_13, edge_point_14, edge_point_15, edge_point_16]
        if if_concave((x_113,y_113),(x_110,y_110),(x_111,y_111),(x_112,y_112))==True:
            inside_point_100 = is_point_inside((x_100, y_100), (x_110, y_110), (x_111, y_111), (x_112, y_112))  # 0-1-2
            inside_point_110 = is_point_inside((x_101, y_101), (x_110, y_110), (x_111, y_111), (x_112, y_112))
            inside_point_120 = is_point_inside((x_102, y_102), (x_110, y_110), (x_111, y_111), (x_112, y_112))
            edge_point_100 = is_point_edge((x_100, y_100), (x_110, y_110), (x_111, y_111), (x_112, y_112))  # 0-1-2
            edge_point_110 = is_point_edge((x_101, y_101), (x_110, y_110), (x_111, y_111), (x_112, y_112))
            edge_point_120 = is_point_edge((x_102, y_102), (x_110, y_110), (x_111, y_111), (x_112, y_112))
            output_list.extend([inside_point_100,inside_point_110,inside_point_120,edge_point_100,edge_point_110,edge_point_120])
        elif if_concave((x_110,y_110),(x_111,y_111),(x_112,y_112),(x_113,y_113))==True:
            inside_point_101 = is_point_inside((x_100, y_100), (x_113, y_113), (x_111, y_111), (x_112, y_112))  # 1-2-3
            inside_point_111 = is_point_inside((x_101, y_101), (x_113, y_113), (x_111, y_111), (x_112, y_112))
            inside_point_121 = is_point_inside((x_102, y_102), (x_113, y_113), (x_111, y_111), (x_112, y_112))
            edge_point_101 = is_point_edge((x_100, y_100), (x_113, y_113), (x_111, y_111), (x_112, y_112))  # 1-2-3
            edge_point_111 = is_point_edge((x_101, y_101), (x_113, y_113), (x_111, y_111), (x_112, y_112))
            edge_point_121 = is_point_edge((x_102, y_102), (x_113, y_113), (x_111, y_111), (x_112, y_112))
            output_list.extend([inside_point_101, inside_point_111, inside_point_121, edge_point_101, edge_point_111, edge_point_121])
        elif if_concave((x_111,y_111),(x_112,y_112),(x_113,y_113),(x_110,y_110))==True:
            inside_point_102 = is_point_inside((x_100, y_100), (x_113, y_113), (x_110, y_110), (x_112, y_112))  # 2-3-0
            inside_point_112 = is_point_inside((x_101, y_101), (x_113, y_113), (x_110, y_110), (x_112, y_112))
            inside_point_122 = is_point_inside((x_102, y_102), (x_113, y_113), (x_110, y_110), (x_112, y_112))
            edge_point_102 = is_point_edge((x_100, y_100), (x_113, y_113), (x_110, y_110), (x_112, y_112))  # 2-3-0
            edge_point_112 = is_point_edge((x_101, y_101), (x_113, y_113), (x_110, y_110), (x_112, y_112))
            edge_point_122 = is_point_edge((x_102, y_102), (x_113, y_113), (x_110, y_110), (x_112, y_112))
            output_list.extend([inside_point_102, inside_point_112, inside_point_122, edge_point_102, edge_point_112, edge_point_122])
        a = output_list.count(())
        for i in range(0, a):
            b = output_list.index(())
            del output_list[b]
        output_list = list(set(output_list))
        if len(output_list)<3:
            return []
        else:
            output_list = remover(output_list)
            return output_list
    if len(shape_0)==4 and len(shape_1)==3: #rectangle-triangle
        x_200 = shape_0[0][0]
        y_200 = shape_0[0][1]
        x_201 = shape_0[1][0]
        y_201 = shape_0[1][1]
        x_202 = shape_0[2][0]
        y_202 = shape_0[2][1]
        x_203 = shape_0[3][0]
        y_203 = shape_0[3][1]
        x_210 = shape_1[0][0]
        y_210 = shape_1[0][1]
        x_211 = shape_1[1][0]
        y_211 = shape_1[1][1]
        x_212 = shape_1[2][0]
        y_212 = shape_1[2][1]
        int_point_20 = line_func((x_200, y_200), (x_201, y_201), (x_210, y_210), (x_211, y_211))  # 01-01
        int_point_21 = line_func((x_200, y_200), (x_201, y_201), (x_211, y_211), (x_212, y_212))  # 01-12
        int_point_22 = line_func((x_200, y_200), (x_201, y_201), (x_212, y_212), (x_210, y_210))  # 01-20
        int_point_23 = line_func((x_201, y_201), (x_202, y_202), (x_210, y_210), (x_211, y_211))  # 12-01
        int_point_24 = line_func((x_201, y_201), (x_202, y_202), (x_211, y_211), (x_212, y_212))  # 12-12
        int_point_25 = line_func((x_201, y_201), (x_202, y_202), (x_212, y_212), (x_210, y_210))  # 12-20
        int_point_26 = line_func((x_202, y_202), (x_203, y_203), (x_210, y_210), (x_211, y_211))  # 23-01
        int_point_27 = line_func((x_202, y_202), (x_203, y_203), (x_211, y_211), (x_212, y_212))  # 23-12
        int_point_28 = line_func((x_202, y_202), (x_203, y_203), (x_212, y_212), (x_210, y_210))  # 23-20
        int_point_29 = line_func((x_203, y_203), (x_200, y_200), (x_210, y_210), (x_211, y_211))  # 30-01
        int_point_210 = line_func((x_203, y_203), (x_200, y_200), (x_211, y_211), (x_212, y_212))  # 30-12
        int_point_211 = line_func((x_203, y_203), (x_200, y_200), (x_212, y_212), (x_210, y_210))  # 30-20
        inside_point_20 = is_point_inside((x_200, y_200), (x_210, y_210), (x_211, y_211), (x_212, y_212))
        inside_point_21 = is_point_inside((x_201, y_201), (x_210, y_210), (x_211, y_211), (x_212, y_212))
        inside_point_22 = is_point_inside((x_202, y_202), (x_210, y_210), (x_211, y_211), (x_212, y_212))
        inside_point_23 = is_point_inside((x_203, y_203), (x_210, y_210), (x_211, y_211), (x_212, y_212))
        edge_point_20 = is_point_edge((x_200, y_200), (x_210, y_210), (x_211, y_211), (x_212, y_212))
        edge_point_21 = is_point_edge((x_201, y_201), (x_210, y_210), (x_211, y_211), (x_212, y_212))
        edge_point_22 = is_point_edge((x_202, y_202), (x_210, y_210), (x_211, y_211), (x_212, y_212))
        edge_point_23 = is_point_edge((x_203, y_203), (x_210, y_210), (x_211, y_211), (x_212, y_212))
        output_list=[int_point_20,int_point_21,int_point_22,int_point_23,int_point_24,int_point_25,int_point_26,int_point_27,int_point_28,int_point_29,int_point_210,int_point_211,
                     inside_point_20,inside_point_21,inside_point_22,inside_point_23,
                     edge_point_20,edge_point_21,edge_point_22,edge_point_23]
        if if_concave((x_203, y_203), (x_200, y_200), (x_201, y_201), (x_202, y_202)) == True:
            inside_point_240 = is_point_inside((x_210, y_210), (x_200, y_200), (x_201, y_201), (x_202, y_202))
            inside_point_250 = is_point_inside((x_211, y_211), (x_200, y_200), (x_201, y_201), (x_202, y_202))
            inside_point_260 = is_point_inside((x_212, y_212), (x_200, y_200), (x_201, y_201), (x_202, y_202))
            edge_point_240 = is_point_edge((x_210, y_210), (x_200, y_200), (x_201, y_201), (x_202, y_202))
            edge_point_250 = is_point_edge((x_211, y_211), (x_200, y_200), (x_201, y_201), (x_202, y_202))
            edge_point_260 = is_point_edge((x_212, y_212), (x_200, y_200), (x_201, y_201), (x_202, y_202))
            output_list.extend([inside_point_260,inside_point_250,inside_point_240,edge_point_240,edge_point_250,edge_point_260])
        elif if_concave((x_200, y_200), (x_201, y_201), (x_202, y_202), (x_203, y_203)) == True:
            inside_point_241 = is_point_inside((x_210, y_210), (x_201, y_201), (x_202, y_202), (x_203, y_203))
            inside_point_251 = is_point_inside((x_211, y_211), (x_201, y_201), (x_202, y_202), (x_203, y_203))
            inside_point_261 = is_point_inside((x_212, y_212), (x_201, y_201), (x_202, y_202), (x_203, y_203))
            edge_point_241 = is_point_edge((x_210, y_210), (x_201, y_201), (x_202, y_202), (x_203, y_203))
            edge_point_251 = is_point_edge((x_211, y_211), (x_201, y_201), (x_202, y_202), (x_203, y_203))
            edge_point_261 = is_point_edge((x_212, y_212), (x_201, y_201), (x_202, y_202), (x_203, y_203))
            output_list.extend([inside_point_261, inside_point_251, inside_point_241, edge_point_241, edge_point_251, edge_point_261])
        elif if_concave((x_201, y_201), (x_202, y_202), (x_203, y_203), (x_200, y_200)) == True:
            inside_point_242 = is_point_inside((x_210, y_210), (x_200, y_200), (x_202, y_202), (x_203, y_203))  # 2-3-0
            inside_point_252 = is_point_inside((x_211, y_211), (x_200, y_200), (x_202, y_202), (x_203, y_203))
            inside_point_262 = is_point_inside((x_212, y_212), (x_200, y_200), (x_202, y_202), (x_203, y_203))
            edge_point_242 = is_point_edge((x_210, y_210), (x_200, y_200), (x_202, y_202), (x_203, y_203))
            edge_point_252 = is_point_edge((x_211, y_211), (x_200, y_200), (x_202, y_202), (x_203, y_203))
            edge_point_262 = is_point_edge((x_212, y_212), (x_200, y_200), (x_202, y_202), (x_203, y_203))
            output_list.extend([inside_point_262, inside_point_252, inside_point_242, edge_point_242, edge_point_252, edge_point_262])
        a = output_list.count(())
        for i in range(0, a):
            b = output_list.index(())
            del output_list[b]
        output_list = list(set(output_list))
        if len(output_list)<3:
            return []
        else:
            output_list = remover(output_list)
            return output_list
    if len(shape_0)==len(shape_1)==4: #rectangle-rectangle
        x_300 = shape_0[0][0]
        y_300 = shape_0[0][1]
        x_301 = shape_0[1][0]
        y_301 = shape_0[1][1]
        x_302 = shape_0[2][0]
        y_302 = shape_0[2][1]
        x_303 = shape_0[3][0]
        y_303 = shape_0[3][1]
        x_310 = shape_1[0][0]
        y_310 = shape_1[0][1]
        x_311 = shape_1[1][0]
        y_311 = shape_1[1][1]
        x_312 = shape_1[2][0]
        y_312 = shape_1[2][1]
        x_313 = shape_1[3][0]
        y_313 = shape_1[3][1]
        int_point_30 = line_func((x_300, y_300), (x_301, y_301), (x_310, y_310), (x_311, y_311))  # 01-01
        int_point_31 = line_func((x_300, y_300), (x_301, y_301), (x_311, y_311), (x_312, y_312))  # 01-12
        int_point_32 = line_func((x_300, y_300), (x_301, y_301), (x_312, y_312), (x_313, y_313))  # 01-23
        int_point_33 = line_func((x_301, y_301), (x_302, y_302), (x_310, y_310), (x_311, y_311))  # 12-01
        int_point_34 = line_func((x_301, y_301), (x_302, y_302), (x_311, y_311), (x_312, y_312))  # 12-12
        int_point_35 = line_func((x_301, y_301), (x_302, y_302), (x_312, y_312), (x_313, y_313))  # 12-23
        int_point_36 = line_func((x_302, y_302), (x_303, y_303), (x_310, y_310), (x_311, y_311))  # 23-01
        int_point_37 = line_func((x_302, y_302), (x_303, y_303), (x_311, y_311), (x_312, y_312))  # 23-12
        int_point_38 = line_func((x_302, y_302), (x_303, y_303), (x_312, y_312), (x_313, y_313))  # 23-23
        int_point_39 = line_func((x_303, y_303), (x_300, y_300), (x_310, y_310), (x_311, y_311))  # 30-01
        int_point_310 = line_func((x_303, y_303), (x_300, y_300), (x_311, y_311), (x_312, y_312))  # 30-12
        int_point_311 = line_func((x_303, y_303), (x_300, y_300), (x_312, y_312), (x_313, y_313))  # 30-23
        int_point_312 = line_func((x_300, y_300), (x_301, y_301), (x_313, y_313), (x_310, y_310))  # 01-30
        int_point_313 = line_func((x_301, y_301), (x_302, y_302), (x_313, y_313), (x_310, y_310))  # 12-30
        int_point_314 = line_func((x_302, y_302), (x_303, y_303), (x_313, y_313), (x_310, y_310))  # 23-30
        int_point_315 = line_func((x_303, y_303), (x_300, y_300), (x_313, y_313), (x_310, y_310))  # 30-30
        output_list=[int_point_30,int_point_31,int_point_32,int_point_33,int_point_34,int_point_35,int_point_36,int_point_37,int_point_38,int_point_39,int_point_310,int_point_311,int_point_312,int_point_313,int_point_314,int_point_315]
        if if_concave((x_303, y_303), (x_300, y_300), (x_301, y_301), (x_302, y_302)) == True:
            inside_point_300 = is_point_inside((x_300, y_300), (x_310, y_310), (x_311, y_311), (x_312, y_312))  # 0-1-2
            inside_point_310 = is_point_inside((x_301, y_301), (x_310, y_310), (x_311, y_311), (x_312, y_312))
            inside_point_320 = is_point_inside((x_302, y_302), (x_310, y_310), (x_311, y_311), (x_312, y_312))
            inside_point_330 = is_point_inside((x_303, y_303), (x_310, y_310), (x_311, y_311), (x_312, y_312))
            edge_point_300 = is_point_edge((x_300, y_300), (x_310, y_310), (x_311, y_311), (x_312, y_312))
            edge_point_310 = is_point_edge((x_301, y_301), (x_310, y_310), (x_311, y_311), (x_312, y_312))
            edge_point_320 = is_point_edge((x_302, y_302), (x_310, y_310), (x_311, y_311), (x_312, y_312))
            edge_point_330 = is_point_edge((x_303, y_303), (x_310, y_310), (x_311, y_311), (x_312, y_312))
            output_list.extend([inside_point_300,inside_point_310,inside_point_320,inside_point_330,edge_point_300,edge_point_310,edge_point_320,edge_point_330])
        elif if_concave((x_300, y_300), (x_301, y_301), (x_302, y_302), (x_303, y_303)) == True:
            inside_point_301 = is_point_inside((x_300, y_300), (x_311, y_311), (x_312, y_312), (x_313, y_313))  # 1-2-3
            inside_point_311 = is_point_inside((x_301, y_301), (x_311, y_311), (x_312, y_312), (x_313, y_313))
            inside_point_321 = is_point_inside((x_301, y_301), (x_311, y_311), (x_312, y_312), (x_313, y_313))
            inside_point_331 = is_point_inside((x_301, y_301), (x_311, y_311), (x_312, y_312), (x_313, y_313))
            edge_point_301 = is_point_edge((x_300, y_300), (x_311, y_311), (x_312, y_312), (x_313, y_313))
            edge_point_311 = is_point_edge((x_301, y_301), (x_311, y_311), (x_312, y_312), (x_313, y_313))
            edge_point_321 = is_point_edge((x_301, y_301), (x_311, y_311), (x_312, y_312), (x_313, y_313))
            edge_point_331 = is_point_edge((x_301, y_301), (x_311, y_311), (x_312, y_312), (x_313, y_313))
            output_list.extend([inside_point_301,inside_point_321,inside_point_331,inside_point_311,edge_point_301,edge_point_311,edge_point_321,edge_point_331])
        elif if_concave((x_301, y_301), (x_302, y_302), (x_303, y_303), (x_300, y_300)) == True:
            inside_point_302 = is_point_inside((x_300, y_300), (x_310, y_310), (x_312, y_312), (x_313, y_313))  # 2-3-0
            inside_point_312 = is_point_inside((x_301, y_301), (x_310, y_310), (x_312, y_312), (x_313, y_313))
            inside_point_322 = is_point_inside((x_301, y_301), (x_310, y_310), (x_312, y_312), (x_313, y_313))
            inside_point_332 = is_point_inside((x_301, y_301), (x_310, y_310), (x_312, y_312), (x_313, y_313))
            edge_point_302 = is_point_edge((x_300, y_300), (x_310, y_310), (x_312, y_312), (x_313, y_313))
            edge_point_312 = is_point_edge((x_301, y_301), (x_310, y_310), (x_312, y_312), (x_313, y_313))
            edge_point_322 = is_point_edge((x_301, y_301), (x_310, y_310), (x_312, y_312), (x_313, y_313))
            edge_point_332 = is_point_edge((x_301, y_301), (x_310, y_310), (x_312, y_312), (x_313, y_313))
            output_list.exten([inside_point_302,inside_point_312,inside_point_332,inside_point_322,edge_point_302,edge_point_322,edge_point_312,edge_point_332])
        if if_concave((x_313,y_313),(x_310,y_310),(x_311,y_311),(x_312,y_312))==True:
            inside_point_340 = is_point_inside((x_310, y_310), (x_300, y_300), (x_301, y_301), (x_302, y_302))
            inside_point_350 = is_point_inside((x_311, y_311), (x_300, y_300), (x_301, y_301), (x_302, y_302))
            inside_point_360 = is_point_inside((x_312, y_312), (x_300, y_300), (x_301, y_301), (x_302, y_302))
            inside_point_370 = is_point_inside((x_313, y_313), (x_300, y_300), (x_301, y_301), (x_302, y_302))
            edge_point_370 = is_point_edge((x_313, y_313), (x_300, y_300), (x_301, y_301), (x_302, y_302))
            edge_point_340 = is_point_edge((x_310, y_310), (x_300, y_300), (x_301, y_301), (x_302, y_302))
            edge_point_350 = is_point_edge((x_311, y_311), (x_300, y_300), (x_301, y_301), (x_302, y_302))
            edge_point_360 = is_point_edge((x_312, y_312), (x_300, y_300), (x_301, y_301), (x_302, y_302))
            output_list.extend([inside_point_340,inside_point_350,inside_point_360,inside_point_370,edge_point_340,edge_point_370,edge_point_350,edge_point_360])
        elif if_concave((x_310,y_310),(x_311,y_311),(x_312,y_312),(x_313,y_313))==True:
            inside_point_341 = is_point_inside((x_310, y_310), (x_301, y_301), (x_302, y_302), (x_303, y_303))
            inside_point_351 = is_point_inside((x_311, y_311), (x_301, y_301), (x_302, y_302), (x_303, y_303))
            inside_point_361 = is_point_inside((x_312, y_312), (x_301, y_301), (x_302, y_302), (x_303, y_303))
            inside_point_371 = is_point_inside((x_313, y_313), (x_301, y_301), (x_302, y_302), (x_303, y_303))
            edge_point_341 = is_point_edge((x_310, y_310), (x_301, y_301), (x_302, y_302), (x_303, y_303))
            edge_point_351 = is_point_edge((x_311, y_311), (x_301, y_301), (x_302, y_302), (x_303, y_303))
            edge_point_361 = is_point_edge((x_312, y_312), (x_301, y_301), (x_302, y_302), (x_303, y_303))
            edge_point_371 = is_point_edge((x_313, y_313), (x_301, y_301), (x_302, y_302), (x_303, y_303))
            output_list.extend([inside_point_341,inside_point_351,inside_point_361,inside_point_371,edge_point_341,edge_point_351,edge_point_361,edge_point_371])
        elif if_concave((x_311,y_311),(x_312,y_312),(x_313,y_313),(x_310,y_310))==True:
            inside_point_342 = is_point_inside((x_310, y_310), (x_300, y_300), (x_302, y_302), (x_303, y_303))
            inside_point_352 = is_point_inside((x_311, y_311), (x_300, y_300), (x_302, y_302), (x_303, y_303))
            inside_point_362 = is_point_inside((x_312, y_312), (x_300, y_300), (x_302, y_302), (x_303, y_303))
            inside_point_372 = is_point_inside((x_313, y_313), (x_300, y_300), (x_302, y_302), (x_303, y_303))
            edge_point_342 = is_point_edge((x_310, y_310), (x_300, y_300), (x_302, y_302), (x_303, y_303))
            edge_point_352 = is_point_edge((x_311, y_311), (x_300, y_300), (x_302, y_302), (x_303, y_303))
            edge_point_362 = is_point_edge((x_312, y_312), (x_300, y_300), (x_302, y_302), (x_303, y_303))
            edge_point_372 = is_point_edge((x_313, y_313), (x_300, y_300), (x_302, y_302), (x_303, y_303))
            output_list.extend([inside_point_342,inside_point_352,inside_point_362,inside_point_372,edge_point_342,edge_point_352,edge_point_362,edge_point_372])
        a = output_list.count(())
        for i in range(0, a):
            b = output_list.index(())
            del output_list[b]
        output_list = list(set(output_list))
        if len(output_list)<3:
            return []
        else:
            output_list = remover(output_list)
            return output_list
print minority_shape_intersect([(-5.,10.),(0,0),(5.,10.)],[(0.,10.),(-5.,0.),(0.,3.),(5.,0.)])
