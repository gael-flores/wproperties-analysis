
#ifndef HEL_SYST_HELPER_H
#define HEL_SYST_HELPER_H

#include <eigen3/Eigen/Dense>
#include <eigen3/unsupported/Eigen/CXX11/Tensor>


using helicity_tensor_t = Eigen::TensorFixedSize<double, Eigen::Sizes<6>>;

template <Eigen::Index D>
class helSystHelper
{
public:
    helSystHelper() {}

    using mass_tensor_t = Eigen::TensorFixedSize<double, Eigen::Sizes<D>>;
    using helicity_mass_tensor_t = Eigen::TensorFixedSize<double, Eigen::Sizes<6, D>>;

    auto operator()(helicity_tensor_t &helicity_tensor, mass_tensor_t &mass_tensor)
    {

        constexpr Eigen::Index nhelicity = 6;

        constexpr std::array<Eigen::Index, 2> broadcastmasses = {1, D};
        constexpr std::array<Eigen::Index, 2> broadcasthelicities = {nhelicity, 1};

        helicity_mass_tensor_t helicity_mass_tensor;
        helicity_mass_tensor = helicity_tensor.reshape(broadcasthelicities).broadcast(broadcastmasses) * mass_tensor.reshape(broadcastmasses).broadcast(broadcasthelicities);

        // std::cout << "-----------------------" << std::endl;
        // std::cout << helicity_mass_tensor << std::endl;
        // std::cout << "-----------------------" << std::endl;

        return helicity_mass_tensor;
    }
};


template <Eigen::Index NptEig>
class helSystSFHelper
{
public:
    helSystSFHelper() {}

    using SF_tensor_t = Eigen::TensorFixedSize<double, Eigen::Sizes<48, NptEig, 2, 2>>;
    using helicity_sf_tensor_t = Eigen::TensorFixedSize<double, Eigen::Sizes<6, 48, NptEig, 2, 2>>;

    auto operator()(helicity_tensor_t &helicity_tensor, const SF_tensor_t &sf_tensor)
    {
        constexpr Eigen::Index nhelicity = 6;

        constexpr std::array<Eigen::Index, 5> broadcastSF = {1, 48, NptEig, 2, 2};
        constexpr std::array<Eigen::Index, 5> broadcasthelicities = {nhelicity, 1, 1, 1, 1};

        helicity_sf_tensor_t helicity_sf_tensor;
        helicity_sf_tensor = helicity_tensor.reshape(broadcasthelicities).broadcast(broadcastSF) * sf_tensor.reshape(broadcastSF).broadcast(broadcasthelicities);

        // std::cout << "-----------------------" << std::endl;
        // std::cout << helicity_sf_tensor << std::endl;
        // std::cout << "-----------------------" << std::endl;

        return helicity_sf_tensor;
    }
};

#endif