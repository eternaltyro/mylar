Package.describe({
    summary: "Principal graph",
});

Package.on_use(function (api) {

    var where = ['client', 'server'];

    api.use(['standard-app-packages', 'accounts-base', 'basic-crypto', 'ejson', 'timing', 'http', 'async'],
	    where);

    api.imply(['standard-app-packages', 'timing', 'async', 'basic-crypto']);
    api.add_files(['graphmodel.js', 'certs.js', 'principal.js', 'collection_hook.js'], where);

    // TODO: just export one variable containing all these
    api.export("Principal");
    api.export("PrincAttr");
    api.export("Principals");
    api.export("is_indexable");
    api.export("rand_field_name");
    api.export("search_field_name");
    api.export("WrappedKeys");
    api.export("active_attacker");
  api.export("generate_princ_keys");
});
