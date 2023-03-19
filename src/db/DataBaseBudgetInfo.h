

#ifndef BUDGET_TRACKER_DATABASEBUDGETINFO_H
#define BUDGET_TRACKER_DATABASEBUDGETINFO_H




#include "IDataBase.h"
#include "../Singleton.h"

template <BudgetTrackerTypes BT,typename ID>
class DataBaseBudgetInfo final: public Singleton<DataBaseBudgetInfo<BT, ID>>, public IDateBase, public IDataBaseService<BT>, public IDataBaseID<BT,ID> {

public:
    void connect() noexcept(false) override;

    void create() noexcept(false) override;

    void drop() noexcept(false) override;

    void update(const BT &bt) noexcept(false) override;

    void insert(const BT &bt) noexcept(false) override;

    void getAll() noexcept(false) override;

    const BT &get(const ID &id) noexcept(false) override;

    void erase(const ID &id) noexcept(false) override;


};



#endif //BUDGET_TRACKER_DATABASEBUDGETINFO_H
