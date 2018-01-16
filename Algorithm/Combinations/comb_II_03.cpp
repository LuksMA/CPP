#include <iostream>
#include <vector>

class Combinator
{
public:
    Combinator(std::vector<std::vector<int> >& vectors)
        : m_vectors(vectors)
    {
        m_combination.reserve(m_vectors.size());
        for(auto& v : m_vectors)
            m_combination.push_back(v.begin());
    }

    bool next()
    {
        // iterate through vectors in inverse order
        for(long long i = m_vectors.size() - 1; i >= 0; --i)
        {
            std::vector<int>::iterator& it = m_combination[i];
            std::vector<int>& v = m_vectors[i];

            if(++it != v.end())
                return true;
            it = v.begin();
        }
        return false;
    }

    std::vector<std::vector<int>::iterator> combination() const
    {
        return m_combination;
    }

private:
    std::vector<std::vector<int> >& m_vectors; // reference to data
    std::vector<std::vector<int>::iterator> m_combination;
};

int main(int /*argc*/, char* /*argv*/ [])
{
    std::vector<std::vector<int> > input = {{0, 1, 2, 4, 5}, {10, 11}, {101, 102, 103, 104, 105}};
    Combinator combinator(input);
    do
    {
        const std::vector<std::vector<int>::iterator> combination = combinator.combination();
        for(const auto& it : combination)
            std::cout << *it << " ";
        std::cout << std::endl;
    } while(combinator.next());
    return 0;
}


//0 10 101
//0 10 102
//0 10 103
//0 10 104
//0 10 105
//0 11 101
//0 11 102
//0 11 103
//0 11 104
//0 11 105
//1 10 101
//1 10 102
//1 10 103
//1 10 104
//1 10 105
//1 11 101
//1 11 102
//1 11 103
//1 11 104
//1 11 105
//2 10 101
//2 10 102
//2 10 103
//2 10 104
//2 10 105
//2 11 101
//2 11 102
//2 11 103
//2 11 104
//2 11 105
//4 10 101
//4 10 102
//4 10 103
//4 10 104
//4 10 105
//4 11 101
//4 11 102
//4 11 103
//4 11 104
//4 11 105
//5 10 101
//5 10 102
//5 10 103
//5 10 104
//5 10 105
//5 11 101
//5 11 102
//5 11 103
//5 11 104
//5 11 105
