#ifndef COUNTMODEL_H
#define COUNTMODEL_H

namespace Model{


    /**
     * @brief The Count model class
     */
    class CountModel
    {
    public:
        CountModel();
        int value();
        void setValue(int);

        int mValue;
    };

}

#endif // COUNTMODEL_H
