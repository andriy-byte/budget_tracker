

#include "Paths.h"
namespace paths{
    namespace db{
        const std::filesystem::path app_db{std::filesystem::current_path() / "db" / "budget_tracker.sqlite"};
    }
}
