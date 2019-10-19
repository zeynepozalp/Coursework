def place_words(corpus):
    global n, l
    def uppercase(corpus):
        new_corpus=[]
        for item in corpus:
            new_corpus.append(item.upper())
        return new_corpus
    def is_ok(corp, lst, item):
        n = len(item)
        l = len(lst)
        output_helper = []
        for c in corp:
            for j in range(n):
                if j in output_helper:
                    continue
                stack = ""
                for i in lst:
                    stack += i[j]
                if stack + item[j] == c[:l + 1]:
                    if not j in output_helper:
                        output_helper.append(j)
                        break
        if n == len(output_helper):
            return True
        else: return False
    def remover(lst, x):
        if x in lst:
            for i in range(len(lst)):
                if lst[i] == x:
                    return lst[:i] + lst[i + 1:]
                continue
        else: return lst
    n = len(corpus[0])
    l = len(corpus)
    def place_words_helper(item):
        temp = remover(corpus, item)
        stack = [item]
        i = 0
        while i < l:
            temp_0 = remover(temp, corpus[i])
            if is_ok(temp, stack, corpus[i]):
                stack.append(corpus[i])
                temp = temp_0
                i = 0
            if len(stack) == n:
                return stack
            else: i += 1
        else: return []
    corpus=uppercase(corpus)
    for item in corpus:
        output=place_words_helper(item)
        if not output==[]:
            return output
    else: return False