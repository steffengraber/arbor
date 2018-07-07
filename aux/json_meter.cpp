#include <arbor/profile/meter_manager.hpp>
#include <nlohmann/json.hpp>

namespace aux {

static nlohmann::json to_json(const arb::profile::measurement& mnt) {
    nlohmann::json measurements;
    for (const auto& m: mnt.measurements) {
        measurements.push_back(m);
    }

    return {
        {"name", mnt.name},
        {"units", mnt.units},
        {"measurements", measurements}
    };
}

nlohmann::json to_json(const arb::profile::meter_report& report) {
    nlohmann::json json_meters;
    for (const auto& mnt: report.meters) {
        json_meters.push_back(to_json(mnt));
    }

    return {
        {"checkpoints", report.checkpoints},
        {"num_domains", report.num_domains},
        {"meters", json_meters},
        {"hosts", report.hosts},
    };
}

}
