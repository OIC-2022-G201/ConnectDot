#pragma once
#include <Mof.h>

#include "vector"
#include <list>
class MainApp
{
    std::vector<Vector2> vectors_;

    std::vector<int> outers;
    bool isRender = false;
    int& n;
public:
    void Initialize()
    {

    }
    void Update()
    {
        if (GetMousePush<MOFMOUSE_LBUTTON>())
        {
            Vector2 result;
            g_pInput->GetMousePos(result);
            vectors_.emplace_back(result);
            isRender = false;
        }
        if (GetMousePush<MOFMOUSE_RBUTTON>())
        {

        }

        if(GetKeyPush<MOFKEY_SPACE>())
        {
            AutoConvexHull();
            isRender = true;
        }
    }
    void Render()
    {

        for (auto vector : vectors_)
        {
            CGraphicsUtilities::RenderCircle(vector.x,vector.y, 5, MOF_COLOR_BLACK);
        }
        int len = outers.size();
        if(len<1 || !isRender)return;
        for (int i = 1; i < len; ++i)
        {
            CGraphicsUtilities::RenderLine(vectors_[outers[i - 1]], vectors_[outers[i]], MOF_COLOR_WHITE);
        }
        CGraphicsUtilities::RenderLine(vectors_[outers[len - 1]], vectors_[outers[0]], MOF_COLOR_WHITE);
    }

    void AutoConvexHull()
    {
        auto iter
            = std::min_element(vectors_.begin()
                , vectors_.end()
                , [](const Vector2& a, const Vector2& b)
                {
                    return b.y < a.y;
                });

        size_t index_a = std::distance(vectors_.begin(), iter);


        int index_b;
        outers.clear();
        do {
            outers.emplace_back(index_a);
            index_b = 0;
            for (int index_c = 1; index_c < vectors_.size(); index_c++) {
                if (index_b == index_a) {
                    index_b = index_c;
                }
                else {
                    CVector2 ab = vectors_[index_b] - vectors_[index_a];
                    CVector2 ac = vectors_[index_c] - vectors_[index_a];

                    auto v = ab.x * ac.y - ab.y * ac.x;
                    if (v > 0 || (v == 0 && ac.Length() > ab.Length())) {
                        index_b = index_c;
                    }
                }
            }
            index_a = index_b;
        } while (index_a != outers[0]);


    }

    template<int key>
    static bool GetMousePush()
    {
        return g_pInput->IsMouseKeyPush(key);
    }
    template<int key>
    static bool GetKeyPush()
    {
        return g_pInput->IsKeyPush(key);
    }
};

