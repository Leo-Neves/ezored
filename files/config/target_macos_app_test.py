def run(proj_path, target_name, params):
    return {
        "project_name": "Test",
        "build_types": ["Debug"],
        "archs": [
            {
                "arch": "x86_64",
                "conan_arch": "x86_64",
                "conan_profile": "ezored_macos_app_test_profile",
                "min_version": "10.9",
            }
        ],
    }
